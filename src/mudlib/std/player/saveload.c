/**
 * ENDOR-MUD'/std/player/saveload.c'
 */

#include "/secure/wizlevels.h"

#include <actions.h>
#include <input_to.h>
#include <properties.h>
#include <colours.h>
#include <moving.h>
#include <equipment.h>
#include <npc.h>
#include <stdrooms.h> // INICIO
#include <characters.h>
#include <sounds.h>
#include <player.h>
#define MAX_IDLE_TIME   1800
#define NO_SAVE_PROPERTIES (["Damage","DefendObj","LastPlayer","DeadOb","HbObj", \
                             P_EQUIP_DATA,"WearData","WieldData", \
                             "Wielded","Worn", \
                             "NoWear","NoWield","NoUnwear","NoUnwield" ])

//----------------------------------------------------------------------------

// /std/base.c
public mixed Set(string pn, mixed arg);
public mixed Query(string pn);

// /std/living/description
public string QueryRealName();
public int QueryInvis();
public varargs string QueryName(mixed true_name);

//----------------------------------------------------------------------------

private string called_from_ip;          /* Nombre de la maquina cliente */
private string llamada_desde;           /* Numero ip de la maquina cliente */

private nosave int player_started = 0;  // Si se ha inicializado ya el jugador

private string home;        // habitacion donde comienza el jugador
private string home_tmp;    // Habitacion donde grabo

private nosave int pLastSave;      // tiempo desde ultima grabacion

private mapping inventory;  /* El sistema de inventario actual:
                        ([objeto:QueryProperties();container]) */

private mapping auto_load;  // autoload mapping

//----------------------------------------------------------------------------
// Query / Set
//----------------------------------------------------------------------------

// Nombre y direccion IP del player
public string QueryIPName()     { return called_from_ip; }
public string QueryIPNumber()   { return llamada_desde; }

// ¿Ha sido inicializado el player?
public int QueryPlayerStarted()     { return player_started; }
public int SetPlayerStarted(int i)  { return QueryPlayerStarted(); }

// Donde el jugador aparece tras un reiniciar o al principio
public string SetHome(string str)   { return home = str; }
public string QueryHome()           { return home; }

// Donde se encuentra el jugador
public string SetHomeTmp(string str)    { return home_tmp = str; }
public string QueryHomeTmp()            { return home_tmp; }

// Ultima vez que grabo
public int QueryLastSave()      { return pLastSave; }
public int SetLastSave(int i)   { return pLastSave; }

// Inventario
public mapping QueryInventory()        { return inventory; }
public mapping SetInventory(mapping m) { return inventory = m; }

//----------------------------------------------------------------------------
// End Query / Set
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Rutinas de autoload
//----------------------------------------------------------------------------

private void reset_autoobject() { auto_load = ([]); }

private void save_autoobject(object ob, int destruct_autos) {
    mixed args;
    string err;

    if (!objectp(ob))
        log_file("AUTOLOAD", ctime() + " Objeto ya destruido\n"
                 "obj: " + object_name());
    else
    {// [Nyh] considero el catch innecesario, pero lo dejo vivir
        if (err = catch(args = ob->Query(P_AUTOOBJECT)))
            log_file("AUTOLOAD", ctime() + " archivo: " + object_name(ob) +
                     "\nobj: " + object_name() + " error al grabar: " + err);
        else if (args) {
            auto_load[blueprint(ob)] = args;
            if (destruct_autos) catch(ob->remove()), ob && destruct(ob);
        }
    }
}

protected void restore_autoobject(string file, mixed args) {
    object ob;
    string err;
    int mret;

    if (err = catch(ob = clone_object(file),
                    ob->Set(P_AUTOOBJECT, args),
                    mret = ob->move(TO, M_NOCHECK)))
    {
        log_file("AUTOLOAD", ctime() + " archivo: " + file +
                 "\nobj: " + object_name() + " error al cargar: " + err);
        if (ob) destruct(ob);
    }
    else if (!ob || mret != ME_OK || environment(ob) != TO)
    {
        log_file("AUTOLOAD", ctime() + " archivo: " + file +
                 "\nobj: " + object_name() + " autoobject erróneo: " +
                 (ob ? object_name(ob) : "- se autodestruyo -") +
                 " mover: " + mret + "\n");
        if (ob) destruct(ob);
    }
}

//----------------------------------------------------------------------------
// Fin Rutinas de autoload
//----------------------------------------------------------------------------




protected int fortune(string str) {
  string leido, fotd, *fortunes;
  int i, b, wiz;

  if (IS_LEARNER(TP) && random(4)) wiz=1;

  if (wiz) leido=read_file("/etc/FORTUNE.WIZ");
  else leido=read_file("/etc/FORTUNE");

  if (!leido) return 1;
  fortunes=explode(leido, "%%\n");
  fotd=fortunes[random(sizeof(fortunes))];

  fotd=W(implode(explode(" "+fotd, "\n"), " "))+"\n";
  fortunes=explode(fotd, "\n");
  if (fortunes[sizeof(fortunes)-1]="\n") fortunes-=({fortunes[sizeof(fortunes)-1]});

  for (i=0; i<sizeof(fortunes); i++)
    fortunes[i]=STR->cadjust(fortunes[i],79);

  fotd=implode(fortunes, "\n");
  if (wiz)
    TO->catch_tell(STR->cadjust(TC_BOLD+"Ayuda del día para el Wizard:"+TC_NORMAL, 83));
  else
    TO->catch_tell(STR->cadjust(TC_BOLD+"Ayuda del día:"+TC_NORMAL, 83));
  TO->catch_tell("\n");
  TO->catch_tell(fotd+"\n\n");
  return 1;
}

//-----------------------------------------------------------------------------

protected _add_commands() {
    TO->add_comm_commands();
    TO->add_view_cmds();
    TO->add_living_cmds();
    TO->add_putget_cmds();
    TO->add_groups_cmds();
    TO->add_misc_commands();
}

//-----------------------------------------------------------------------------

private void actualize_containers(object ob, string name) {
    mixed *idx;
    int i;

    idx = m_indices(inventory||([]));
    for (i=sizeof(idx); i--; )
        if (inventory[idx[i],1]==name)
            inventory[idx[i],1]=object_name(ob);
}

protected void _restore_inventory() {
    mapping objects = ([]);
    mixed *idx;
    string str, *equipar = ({});
    int i;
    object cont, ob;

    if (mappingp(auto_load)) walk_mapping(auto_load, SF(restore_autoobject));


    idx = m_indices(inventory||([]));
    str = lower_case(blueprint());

  //clonarlo todo y dejarlo en el vacío sideral...
  // [Nyh] Ahora solo deja en el vacio aquello que estuviese en un contenedor
    for (i=sizeof(idx); i--; )
    {
        if (!catch(ob=clone_object(blueprint(idx[i]))))
        {
            mapping m = inventory[idx[i]];

            if (sizeof(m))
            { // Estas lineas son para pasar el equipo viejo al nuevo
              if (m["Wielded"  ]) { m[P_EQUIPPED]  = m["Wielded"  ]; m_delete(m, "Wielded"  ); }
              if (m["Worn"     ]) { m[P_EQUIPPED]  = m["Worn"     ]; m_delete(m, "Worn"     ); }
              if (m["NoWear"   ]) { m[P_NOEQUIP]   = m["NoWear"   ]; m_delete(m, "NoWear"   ); }
              if (m["NoWield"  ]) { m[P_NOEQUIP]   = m["NoWield"  ]; m_delete(m, "NoWield"  ); }
              if (m["NoUnwear" ]) { m[P_NOUNEQUIP] = m["NoUnwear" ]; m_delete(m, "NoUnwear" ); }
              if (m["NoUnwield"]) { m[P_NOUNEQUIP] = m["NoUnwield"]; m_delete(m, "NoUnwield"); }

              ob->SetProperties(m - ([P_EQUIPPED]) - NO_SAVE_PROPERTIES);
            }
            actualize_containers(ob, idx[i]); //Por que los contenedores han cambiado de #<numero>

            // El lower_case es porq antes era /Nyh y ahora es /nyh
            if (lower_case(inventory[idx[i], 1]) == str) //str es el player
            {// Si NO estaba en un contenedor, me mueve al player
                if ( ob->move(TO, M_NOCHECK) == ME_OK )
                {
                    if (m[P_EQUIPPED])
                    { // Se pone el equipo
                        ob->Equip(TO, EWF_SILENT|EWF_WEAPON);
                        equipar += ({ ob->QueryShort() });
                    }
                }
                else if (ob->move(environment(TO), M_SILENT) != ME_OK)
                {
                    ob->remove();
                    if (ob) destruct(ob);
                }
            } // En objects guardo lo q estaba dentro de containers, para luego moverlo
            else {
                objects += ([ idx[i]: ob ]);
            }
            //'Vacía' los contenedores...
            if ( member(inherit_list(ob), "/std/container.c") != -1 )
            {
                ob->AddIntWeight(-ob->QueryWeightContent());
                ob->SetWeightContent(0);
            }
        }
        else
        {
            log_file("INVENTARIO", ctime()+" No puedo clonar: "+idx[i]+
	             " para "+capitalize(TP->QueryRealName())+".\n");
    	}
    }

    if (sizeof(equipar))
        TO->catch_msg("Te equipas con "+implode(equipar[0..<2], ", ") + (sizeof(equipar)>1?" y ":"")+equipar[<1]+".\n");

    //meter los objetos que estaban en containers...
    for (i=sizeof(idx = m_indices(objects||([]))); i--; )
    {
        ob = objects[idx[i]];
        if (ob->Query(P_EQUIPPED)) continue;
        if (cont = find_object(inventory[idx[i],1]))
        {
            if (    (ob->move(cont, M_NOCHECK) != ME_OK)
                 && (ob->move(environment(TO), M_SILENT) != ME_OK))
            {
                ob->remove();
                if (ob) destruct(ob);
            }
        }
        else
        {
            log_file("INVENTARIO", ctime()+" El objeto padre ("+
                     inventory[idx[i],1]+") de ("+idx[i]+
                     ") no ha sido clonado todavía para "+
                     capitalize(TP->QueryRealName())+".\n");
        }
    }
    auto_load = 0;
}

protected void _move_player_to_start(int newflag) {
    int i;

    if (!home_tmp || home_tmp =="" || catch(i = TO->move(home_tmp, M_SILENT)) || i != 1)
        if (!home || home == "" || catch(i = TO->move(home, M_SILENT)) || i != 1)
            TO->move(INICIO, M_TELEPORT);

    if (environment(TP)) TO->catch_tell("Te materializas en "+(environment(TP)->QueryLocate()||environment(TP)->QueryIntShort(1)));
    else TO->catch_tell("Por algún error no has podido ser movido a ningún sitio");
    TO->catch_tell(".\n");
    if (QueryInvis()) TO->fvis();

    if (!newflag) CHANNELMASTER->SendEmote("infomud", capitalize(getuid(TO))+" desciende a la Tierra Media", SOUND_EVENTOS("conexion"));
    else
    {
        CHANNELMASTER->SendEmote("infomud", "A instancias de Ilúvatar, un nuevo espíritu \n"
        " penetra en Ea y nace como uno de sus hijos en Arda con el nombre de " + CAP(TO->QueryName()) + "", SOUND_EVENTOS("conexion"));
    }

}

//-----------------------------------------------------------------------------
/*
 *-----------------------------------------------------------------
 * start_player: Esta funcion es llamada por el login.c
 * restart_player: Para que reempiecen jugadores desconectados
 *-----------------------------------------------------------------
 */

public void _send_nick_info()
// se envía información sobre si su nick no ha sido validado
{
    TO->catch_tell(TC_RED + "¡Atención! Tu nombre no ha sido validado todavía.\n"
                   "Para más información, escribe 'ayuda nombres' o contacta con un "
                   "Vala.\n" + TC_NORMAL);
}

start_player( str) {
    int newflag;  /* could player be restored? */
    int valid;
    string realname, rc;

    if (load_name(PO) != LOGIN) return 0;

    TO->SetName(capitalize(str));
    realname = TO->QueryRealName();


    /* try to restore player. If it doesn't exist, set the new flag */
    rc = catch(restore_object("/" SAVEPATH+realname[0..0]+"/"+realname));
    if (!QueryAge()) newflag = 1;

    if (rc) write("***** Tu personaje no puede ser restablecido correctamente.\n");

    Set(P_CLEAN_UP, 0);  /* Make sure that players are here to stay! */

    TO->RestoreAttrs();

    if (catch(RACEMASTER->RestoreRace(TO))) {
        write("***** Tu personaje no tiene una raza definida.\n");
        rc = 1;
    }


    if (TO->QueryLevel() <= 0) {
        TO->SetLevel(1);
        TO->SetHP(QueryMaxHP());
        TO->SetFood(QueryMaxFood());
        TO->SetDrink(QueryMaxDrink());
    }

    enable_commands();

#ifdef MWHOD_DEMON
    /* call mudwho to register player */
    MWHOD_DEMON->send_user_login(TP);
#endif

    TO->GetHeart(HEART_HEAL); // to be sure
    TO->ValidizeHeart();
    TO->config_soul(); // En el soul

    _add_commands();

    // si el nombre no ha sido aún validado, se le informa
    if ((valid = CHARMASTER->QueryValidName(realname)) == NICK_UNKNOWN || valid == NICK_PENDING)
    {
        if (valid == NICK_UNKNOWN)
        {
            if (TO->QueryGuildLevel() > 1)
            {
                valid = NICK_VALID;
                CHARMASTER->AcceptName(realname);
            }
            else CHARMASTER->AddPendingName(realname);
        }
    }
    if (valid != NICK_VALID) call_out("_send_nick_info", 4);
    TO->catch_tell(read_file("/etc/NEWS"));

    fortune();

    _move_player_to_start(newflag);

/*
  if (called_from_ip && query_ip_name() != called_from_ip)
    TO->catch_tell("La última vez que entraste lo hiciste desde " + called_from_ip + ".\n");
*/
    called_from_ip = query_ip_name();
    llamada_desde = query_ip_number();

    _restore_inventory();

    player_started = 1;

    autosave(1);

    TO->SetPrompt(TO->QueryPrompt());

#ifdef LOG_ENTER
    if (!QueryInvis()) {
	    log_file("ENTRA", realname + ", " + ctime(time())[4..15]+ ", "+
          	   query_ip_name(TO)+".\n");
    }
#endif

    if (rc) write("***** Contacta con un Vala.\n");
    return 1;
}

//----------------------------------------------------------------------------

void restart_player(string name) {
  object *u;
  int i;
  string *col;

  if (!IS_LEARNER(TO) || !QueryInvis()) {
    CHANNELMASTER->SendEmote("infomud", capitalize(getuid(TO))+" regresa a la Tierra Media", SOUND_EVENTOS("regresar"));
  }
  else {
    for (i=sizeof(u=users()); i--; ) {
      if (TO != u[i] && IS_LEARNER(u[i])) {
        tell_object(u[i], TC_MUD_WHO + "[mud: " + TC_NORMAL
                        + TC_MUD_MSG + capitalize(getuid(TO)) + " regresa a Endor" + TC_NORMAL
                        + TC_MUD_WHO + "]" + TC_NORMAL + "\n");
      }
    }
  }

  if (QueryInvis()) write("Te encuentras en estado incorpóreo, ningún mortal puede percibirte\n");

  if (called_from_ip && query_ip_name() != called_from_ip)
    TO->catch_tell("A nosotros nos da igual, pero a Gollum le \n"
    " interesa saber que tu última conexión fue desde " + called_from_ip + ".\n");
  called_from_ip = query_ip_name();
  llamada_desde = query_ip_number();
  autosave(1);
#ifdef LOG_ENTER
  if (!QueryInvis()) {
	  log_file("ENTRA", getuid(TO) + ", " + ctime(time())[4..15]+ ", "+
        	   query_ip_name(TO)+"\n");
  }
#endif
  TO->SetPrompt(TO->QueryPrompt());

  if (CHARMASTER->QueryValidName(NREAL(TO)) == NICK_UNKNOWN) call_out("_send_nick_info", 4);
}

//----------------------------------------------------------------------------

/*
 * save character: we also need to build the autoload list here.
 * Scan through all objects in the inventory and put objects with
 * Query(P_AUTOOBJECT) <> 0 into the list.
 */
// [Nyh] Esto puede provocar too longs evaluations cuando se usan containers
public int save() {
    object *inv, ob, bp;
    int i;
    mapping m;

    if (TP != TO && (!PO || object_name(PO) != MASTER)) return 0;

    TO->update_age();

    auto_load = ([]);
    inventory = ([]);

    pLastSave = time();

    for (i = sizeof(inv = deep_inventory()); i--; ) {
      if (!( (ob = inv[i]) && (bp = load_object(blueprint(ob))) ) ) continue;

      if (interactive(ob)) {
        if (environment()) {
          TO->catch_tell(capitalize(ob->QueryShort()||"Algo")+" sale de tu inventario.\n");
       	  ob->move(environment());
        }
        else ob->remove();
      }
      else if (ob->Query(P_AUTOOBJECT)) { //por si esta dentro de un container
	    if (environment(ob)!=TP) ob->move(TP);
	    save_autoobject(ob, 0);
      }
      else { // [Nyh] Compacto mil lineas en la siguiente funcion:
        m = filter( ob->QueryProperties() - NO_SAVE_PROPERTIES,
                    (: return $2!=$3->Query($1); :), bp);

        m[P_WEIGHT] = ob->QueryWeight(1);

        if (m[P_EQUIPPED]) m[P_EQUIPPED]=1;

        inventory += ([object_name(ob): m; object_name(environment(ob)) ]);
      }
    }

    save_object("/"SAVEPATH+TO->QueryRealName()[0..0]+"/"+TO->QueryRealName());

    auto_load = 0;

    return 1;
}

/* We can't use normal saving here, since some objects change our stats */
public int remove() {
  object *inv;
  int i;
  string err;

  /* HBSTAT */
  TO->hbstat_flush();

/* DESTRUCCION DEL INVENTARIO [t] */

  inv = deep_inventory(TO);

  for (i=sizeof(inv); i--;)
  {
    catch(inv[i]->remove());
    if (inv[i]) destruct(inv[i]);
  }

  MASTER->update_last_time(TO);

  // actualizamos la última vez que nos conectamos
  destruct(TO);
  return 1;
}

// Funcion llamada cuando se abandona
// Graba y borra el jugador si esta en condiciones de hacerlo o si esta forzado.
public int destruct_player(int force) {
  object ob;

  if (!force && TO->Fighting())
    return notify_fail("¡No puedes dejarlo en mitad de un combate!\n");

  // comprobamos si el nombre no es válido, en cuyo caso, borramos la ficha
  if (!CHARMASTER->QueryValidName(TNREAL))
  {
    TO->catch_tell("Sentimos no poder aceptar tu nombre. Por favor, créate un personaje con "
                   "un nombre más adecuado. Te recomendamos que te leas las normas de nombres "
                   "que aparecen al entrar en la pantalla de creación, para hacerte "
                   "una idea de qué es lo que buscamos en el nombre de un personaje.\n");

    load_object("/secure/remover")->remove_player(NREAL(TO), 1, 1);
    remove();
    if (TO) destruct(TO);
    return TO && 0;
  }
  TO->catch_tell("Salvando "+capitalize(QueryRealName())+".\n");
  save();
#ifdef LOG_COMBAT_STATISTICS
  if ( (ob=TO) && !IS_LEARNER(ob) && ob->QueryGolpes() )
    write_file("/log/combat/estadisticas.log",
    sprintf("[%2i](%2i) %O\b> Atq=%4i (A:%4i / F:%4i)\tDam= Tot:%O Par:%O\n",
        ob->QueryLevel(), ob->QueryGuildLevel(),
        "\b"+STR->ladjust(capitalize(ob->QueryRealName())+": "+ob->QueryRace()+" "+(ob->QueryGuild()||"sin gremio")+" ",34,"-"),
        ob->QueryGolpes(), ob->QueryAciertos(), ob->QueryFallos(),
        ob->QueryDanyoMedioTotal(), ob->QueryDanyoMedio()
        )
    );
#endif
  if (!QueryInvis()) say(QueryName() + " pierde nitidez hasta desaparecer.\n");
  remove();
  if (TO) destruct(TO);
  return TO && 0;
}

cmd_reiniciar(arg) {
  int i;
  object *inv, *obs;
  string path, foo;
  mixed val;

  if(arg) return 0;
  TO->catch_tell("Reiniciando "+capitalize(QueryRealName())+"...\n");

  if (!sizeof(home)) home_tmp = INICIO;
  else home_tmp = home;

  auto_load = ([]);
  pLastSave = time();
  inventory = ([]);

//[t] No existe 'really all', sino el "todo". Emulo 'really all' con PUTGET_REALLY
  obs = all_inventory(TP);

  for (i=sizeof(obs); i--; ) {
    if (!obs[i]->Query(P_AUTOOBJECT)) obs[i]->remove();
    else save_autoobject(obs[i], 1);
  }

  if (environment(TO)) environment(TO)->PlayerNetdead(-1);

  catch(map_objects(QueryFollowers()||({}), "PlayerNetdead", -1));

  destruct_player(1);

  return 1;
}

// Envía el mensaje de que abandonamos el mundo y reproducimos el sonidillo
public void NotifyExit()
{
    if (MASTER->find_userinfo(getuid(TO)))
    {
        if (TO->QueryAge()){
                        load_object(CHANNELMASTER)->SendEmote("infomud",
                                           capitalize(NNAME(TO)) + " abandona la Tierra Media", SOUND_EVENTOS("desconexion"));
                                                                                   }//if age
                                                                                   if (query_idle(TO) >= MAX_IDLE_TIME){
                                                                                    load_object(CHANNELMASTER)->SendEmote("valar",
                                           "ha estado demasiado tiempo pasiv"+TO->QueryGenderEndString()+" y el mud le ha echado", SOUND_AINU("canal_ainu"));
                                        } // if sin actividad.
    }
    else
    {
        load_object(CHANNELMASTER)->SendEmote("infomud", capitalize(TNAME) +
                                           " ha partido de Arda para siempre, más allá\n"
                                           " de los confines de Éa, y tan sólo Eru\n"
                                           " conoce el Destino que le aguarda.", SOUND_EVENTOS("desconexion"));
    }
}

