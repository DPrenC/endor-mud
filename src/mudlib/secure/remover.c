/**
 * SIMAURIA '/secure/remover.c'
 */

/*
   NOTA: Un jugador sera borrado si su edad en semanas excede la formula
         de '1 + xp-nivel * (xp-nivel <= 10 ? 6 :12)' semanas.
         NO se borrarán los jugadores que estén baneados.
*/

#include "/secure/config.h"
#include "/secure/wizlevels.h"
#include "/secure/userinfo.h"
#include<characters.h>

#define LEVEL 14

#define LOGFILE  "ELIMINAR"
#define LOGSUGG  "A_ELIMINAR"
#define LOGREM   "ELIMINADO"

#define MUMMYDIR "/secure/momias/"
#define SAVEFILE "/secure/save/.remover"
#define DELAY 10

#define ONEWEEK 604800

#define DEBUG 0


  /* Recuperado de los ficheros de los jugadores */
int level;
int experience;
int pLastSave;
int aLevel;
int aXP;
int bRemoved;

  /* Almacena el tiempo de la ultima vez que se ejecuto. */
int last_run;

/*------------------------------------------------------------------------*/

static int dirno;
static string abc = "abcdefghijklmnopqrstuvwxyz";
static int ctotal, cnopl, csugg, cpl, cbogus;
static int stotal, snopl, ssugg, spl, sbogus;
static int nrnopl, nrpl, nrsugg;
static mixed *files;  /* Ficheros para comprobar de un directorio */
static string bname;  /* Path del directorio actual */
static int base;

#if DEBUG

static string msg;
void addmsg(string m)
{
  if (!msg) msg = m;
  else msg += m;
}
void writemsg()
{
  write_file("/log/REMOVE.debug", msg);
  msg = 0;
}
#else
#define addmsg(m)
#define writemsg()
#endif


create() {
  seteuid(getuid(TO));

  if (-1 != member(object_name(TO), '#')) {
    log_file (LOGFILE,
 ctime(time())+": Illegal attempt!\n"
 "  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
 "  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
 "  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    destruct (TO);
    return;
  }
}

/*------------------------------------------------------------------------*/
/* Comprueba todos los ficheros buscando jugadores a eliminar.
 * Esta funcion solo debe ser llamada por el MASTER.
 */

_start_dragon_1() {
  dirno = 0;
  log_file (LOGFILE, ctime(time())+": Checking /save\n");
  scan_dirs();
}

start_dragon() {
  if (   PO != find_object(MASTER)
      || getuid(TO) != ROOTID
      || -1 != member(object_name(TO), '#')) {
    log_file (LOGFILE,
 ctime(time())+": check_all_players(): Illegal attempt!\n"
 "  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
 "  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
 "  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    destruct (TO);
    return;
  }

  if (restore_object(SAVEFILE)
      && last_run + ONEWEEK - 3600 > time()) {
    destruct (TO);
    return;
  }

  last_run = time();
  save_object(SAVEFILE);
  call_out("_start_dragon_1",10);
}

/*------------------------------------------------------------------------
** Elimina los datos de un jugador/wiz de forma manual.
*/

public varargs int remove_player(string name, int nowiz, int silent)
{
  int rc, wlvl, dirempty, doecho;
  string tmp, *dir;
  mixed *secundary;
  mixed *uinfo;
    int i;

  if (!stringp(name)) {
    write("No se ha dado ningun nombre.\n");
    return 0;
  }
  name = lower_case(name);
  uinfo = MASTER->find_userinfo( name );

  if( !uinfo )
     return notify_fail( "No existe ningún '" + capitalize( name ) + "'.\n" ), 0;

  if (   !(object_name(efun::blueprint(PO)) == SECUREPATH "login")
      && (   !TI
          || TI != TP
          || (   !(IS_GOD(TI) || IS_CON(TI) ) && (name != getuid(TI) /*|| TI != PO*/))
          || ( uinfo[USER_LEVEL] >= query_wiz_level( TI ) && name != getuid( TI ) )
    )  )
    {
    log_file (LOGREM,
 ctime(time())+": remove_player( \""+name+"\" ): ¡Intento ilegal!\n"
 "  this_object:      "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  previous_object:  "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
 "  this_player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
 "  this_interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    write("No tienes permiso para hacer eso.\n");
    return 0;
  }

  if (   file_size("/"+SAVEPATH+name[0..0]+"/"+name+".o") < 0
      && !find_object(name)
     ) {
    write("No existe ningun jugador que se llame '"+capitalize(name)+"' en Simauria.\n");
    return 0;
  }

  if (nowiz && (wlvl = query_wiz_level(name))) return 0;

  dirempty = 1;
  dir = ({});

  doecho = (!silent && query_wiz_level(TP));

  log_file(LOGREM, ctime()+": "+capitalize(getuid(TI))+" removes "
                   +(wlvl ? "wizard" : "player")
                   +" "+capitalize(name)+" ("
                   +(wlvl ? "w" : "")+wlvl+")\n"
          );

  if (!silent) write("Borrando la ficha de "+capitalize(name)+" En Endor-Mud...\n");

  if (name != getuid(TI)) {
    object pl;
    if (pl = find_object(name)) {
      tell_object(pl, "=== Este personaje acaba de ser eliminado ===\n");
      catch(pl->remove());
      if(pl)
        destruct(pl);
      if (doecho) write("  Eliminado "+capitalize(name)+".\n");
      log_file(LOGREM, "  Jugador Eliminado.\n");
    }
  }



  /* Elimina el fichero de save.
   */
  tmp = SAVEPATH+name[0..0]+"/"+name+".o";
  if (file_size(tmp) >= 0) {
    rc = rm(tmp);
    tmp = "  "+tmp+(rc ? "" : " no ha sido")+" eliminado\n";
  }
  else
    tmp = "  No existe ese fichero en save.\n";
  log_file(LOGREM, tmp);
  if (doecho) write(tmp);

  /* cuentas de los bancos */
  if (BANKOBJECT->CloseAccounts(uinfo[USER_ID]) && doecho)
  {
    write("Cuentas bancarias eliminadas.\n");
  }
  /* comprueba si es personaje principal y si tiene secundarios, y de ser así,
     asigna como principal de todos sus secundarios al personaje más antiguo */
 if (sizeof(secundary = MASTER->find_secundary_characters(uinfo[USER_NAME])))
  // Tiene personajes secundarios. Colocamos como principal al más antiguo
  {
    string main_name;
    MASTER->update_secundary_characters(uinfo[USER_ID], (main_name = secundary[0][AR_NAME]));
    if (doecho)
    {
        write("Convirtiendo a todos los personajes secundarios de " + CAP(uinfo[USER_NAME]) +
              " en personajes secundarios de" + CAP(main_name) + ".\n");
    }
  }

  /* Elimina la referencia al personaje en la base de datos.
   */
 MASTER->delete_character(uinfo[USER_ID]);
 return 1;
}

/*------------------------------------------------------------------------
** Scan through all dirs /save/? and check the save-files in them
** with scan_files(). This implies chaining by call_outs.
*/

static scan_dirs() {
  if (dirno >= strlen(abc)) return;
  bname = "/save/"+abc[dirno..dirno]+"/";
  files = get_dir (bname+abc[dirno..dirno]+"*", 7);
  base = 0;
  dirno++;
  scan_files();
}


/*------------------------------------------------------------------------
** Scan the files contained in *files, taken from the save-directory
** denoted by bname. The check is done in bunches of 20 files, chained
** by call_outs.
** The save-files are checked for validity and if the character is
** expired (wasn't logged in for long time). If yes, it is removed.
*/

static scan_files() {
  int bunch, i, rc, age, lvl, wlvl;
  string pname, tmp;
  mixed secundary;


    /* Do at max. 20 files == 60 entries */
  if ((bunch = sizeof(files) - base) > 60) bunch = 60;
  for (i = base; i < base+bunch; i+= 3) {
    age = (time() - files[i+2]) / ONEWEEK;
addmsg(sprintf("%s: file age %d\n", files[i], age));
    if (files[i+1] <= 0 || age <= 4) {
addmsg(sprintf("%*s  -> no file or younger than 4\n", strlen(files[i]), ""));
      continue; /* Hyp */
    }
    pname = files[i][0..<3];

      /* If the savefile can't be read, denote it as 'bogus',
      ** but don't remove it (yet).
      */

    pLastSave = 0;
    experience = aXP = 0;
    level = aLevel = 0;

    if (catch (rc = restore_object (bname+pname)) || !rc) {
      if ( /* rc = rm(bname+files[i]) */ rc = 0, 1 ) {
        sbogus += files[i+1]; cbogus++;
        stotal += files[i+1]; ctotal++;
      }
      log_file (LOGFILE,
                "  Bogus "+bname+files[i]+(rc ? "" : " not")+" removed\n"
		);
addmsg(sprintf("%*s  -> bogus\n", strlen(files[i]), ""));
      continue;
    }
    if (!experience && aXP)
      experience = aXP;
    if (!level && aLevel)
      level = aLevel;

addmsg(sprintf("%*s  xp %d, level %d\n", strlen(files[i]), "", experience, level));
    /* If the save-date is stored, use that instead of the file-date. */
    if (pLastSave)
    {
      age = (time() - pLastSave) / ONEWEEK;
addmsg(sprintf("%*s  read age %d\n", strlen(files[i]), "", age));
      if (age <= 4)
      {
addmsg(sprintf("%*s  -> younger than 4\n", strlen(files[i]), ""));
	continue;
      }
    }

      /* If this file is banished, dont remove it.
      */
    if (DBMASTER->QueryBanishedName(pname))
    {
addmsg(sprintf("%*s  -> mumificado\n", strlen(files[i]), ""));
      continue;
    }

      /* Compare the allowed not-login-time according to the level
      ** of the character.
      */
    wlvl = query_wiz_level(pname);
    if (wlvl) lvl = LEVEL;
    else lvl = xp2level(experience);
    if (lvl < 1)
      lvl = 1;

addmsg(sprintf("%*s  lvl %d, wlvl %d\n", strlen(files[i]), "", lvl, wlvl));
      /* If the character is an absent wizard, suggest the compressions
      ** of its directory.
      */
    if (wlvl >= LEARNER_LVL && (age >= 52) && (age <= 56)) {
      tmp = get_dir("/players/"+pname+"/*");
      if (   pointerp(tmp)
          && sizeof(tmp-({".", "..", ".err", pname+".tar.gz", pname+".tar.z"}))
         )
        log_file (LOGSUGG,
                  capitalize (pname)+" : wlvl "+wlvl+", "+age
                  +" weeks -- suggested for compression.\n");
addmsg(sprintf("%*s  = wizard suggested for compression\n", strlen(files[i]), ""));
      continue;
    }

    if (lvl < LEVEL && age <= 1 + (lvl-1) * 6)
    {
addmsg(sprintf("%*s  -> lvl < %d && age < %d\n", strlen(files[i]), "", LEVEL, 1+(lvl-1)*6));
      continue;
    }

      /* If the character is an expired wizard/player, suggest its removal.
      */
    if (wlvl >= LEARNER_LVL) {
      if (age <= 1 + (LEVEL-1) * 6)
      {
addmsg(sprintf("%*s  -> wizard and age < %d\n", strlen(files[i]), "", 1+(LEVEL-1)*6));
	  continue;
      }
      log_file (LOGSUGG,
                capitalize (pname)+" : wlvl "+wlvl+", "+age+" weeks.\n");
      ssugg += files[i+1]; csugg++;
      stotal += files[i+1]; ctotal++;
      nrsugg++;
addmsg(sprintf("%*s  = wizard suggested\n", strlen(files[i]), ""));
      continue;
    }
    if (lvl >= LEVEL) {
      if (age <= 52)
      {
addmsg(sprintf("%*s  -> lvl > %d and age <= 52\n", strlen(files[i]), "", LEVEL));
	  continue;
      }
      log_file (LOGSUGG,
                capitalize (pname)+" :  lvl "+lvl+", "+age+" weeks.\n");
      ssugg += files[i+1]; csugg++;
      stotal += files[i+1]; ctotal++;
      nrsugg++;
addmsg(sprintf("%*s  = player suggested\n", strlen(files[i]), ""));
      continue;
    }

addmsg(sprintf("%*s  = removed\n", strlen(files[i]), ""));
      /* The character is an expired (super-)player.
      ** All of its possible files are now removed.
      */

      /* Remove the savefile.
      */
    if (rc = rm (bname+files[i])) {
      if (wlvl) snopl += files[i+1], cnopl++, nrnopl++;
      else spl += files[i+1], cpl++, nrpl++;
      stotal += files[i+1]; ctotal++;
    }
    log_file (LOGFILE,
              "  "+bname+files[i]+" [lvl "+lvl+", "+age+" weeks]"
	      +(rc ? "" : " not")+" removed\n"
	      );

    /* Remove the character of database
    */
    if (sizeof(secundary = MASTER->find_secundary_characters(pname)))
    // Tiene personajes secundarios. Colocamos como principal al más antiguo
    {
      MASTER->update_secundary_characters(pname, secundary[0][AR_NAME]);
  }
  if (MASTER->delete_character(pname))
    {
      if (wlvl) snopl += files[i+1], cnopl++;
      else spl += files[i+1], cpl++;
      stotal += files[i+1]; ctotal++;
      log_file (LOGFILE,
                pname + " removed from characters database\n");
    }
  } /* for */

writemsg();
    /* Chain the next operation: next bunch of files
    ** or next directory.
    */
  base += bunch;
  if (base >= sizeof(files)) call_out ("scan_dirs", DELAY);
  else call_out ("scan_files", DELAY);
}