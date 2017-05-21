/* SIMAURIA '/obj/lib/guildobj.c'
   ==============================
   [w] Woo@simauria
   [t] Theuzifan@simauria
   [n] Nemesis@simauria

   11-10-98 [w] Comentadas las lineas que tenian algo que ver con los
                auto_objects ya que daban algun que otro problema, asi
                tambien he modificado un poco la funcion check_owner
                porque no se porque daba un error al comprobar el
                Guild de este objeto. Se pueden buscar las lineas
                cambiadas con '[w]'. Un ligero parche pa que funcione.
   12-11-98 [n] Descomentadas las lineas que comento Woo. El pobre Uzi
                se volvio ayer carioco buscando el puto SetAutoObject.
                (Linea 113 y funciones Set y QueryAutoObject).
                Esas lineas no dan problemas. O al menos a mi no.
                Y yo tengo la ultima version del guild.c y companyia!
                Tio, lee las cabeceras de las funciones. Estan pa algo.
                Por cierto, aki falta una cabecera asin de gorda (mirar
                elefante para hacerse idea del tamaño) que explica como
                joroñas se usa el guildobject y tal y cual. Vale que le
                quites protagonismo a los Wizs de NF, pero al menos deja
                la explicacion de como se usa ello y tal...
   23-11-98 [t] Traducido y adaptado. Añadido el geteuid pa que rule.
   01-03-99 [n] Castellanizado de guays.
   10-03-99 [w] Vuelto a modificar check_owner, de paso he puesto la
                cabecera antigua de NF que demandaba Nemy :)
   14-03-99 [w] Modificado ahora el check_owner tal y cual está en NF
                en estos instantes.
   07-04-99 [w] Añadido el include <magia.h>
   29-04-03 [h] Importante: El objeto de gremio se lleva en la lisa de
   		P_EQUIP_OBJ, y resulta que desde el equipment.c cada vez
   		que te pones/quitas/empuñas/desempuñas algo llama a las
   		funciones Notify/Chk Equip/Equip de todos los P_EQUIP_OBJ y
   		pasaba que esas funciones estan definidas su base (que es la
   		funcion vacia) en el equipment.c, asi que hago que esto herede
   		el equipment por ser necesario (realmente todos los objetos de
   		gremio heredan ambos archivos, pero al ser algo NECESARIO lo
   		meto aqui)
*/
/*
** The std-guildobject
** You may inherit this in addition to /std/thing, /std/weapon, etc.
** to get a guildobject fully compatible to the /std/guild.
**
** It implements three functions which may be added to the guildobject
** via add_action(<function>,<command>):
** cmd_gwho - show all guildmembers (+creator/maintainer) who are online
**            Invis Players won't be shown.
** cmd_gtp - Command for guildleaders to teleport to the guild at 'any'
**           time, i. e.
**           1. The common teleport rules are checked
**           2. The player mustn't be in a virtual room (to ensure (s)he
**              might return to the place at any time.
**           When teleported, the guildleader can't leave the guild except
**           by typing the command 'gtp' again ... or quit, which will
**           teleport her/him back, too.
** cmd_gidea
** cmd_gbug
** cmd_gtypo - These commands just work like 'idea', 'bug' and 'typo' but
**             as those will only log into the rep-file the room in which
**             someone is standing belongs to, this often doesn't help
**             if there's a bug, ... in a guild-ability
**             The reports will be saved in /log/rep/<path>, where <path>
**             is the second part of the path in the file-name, e. g.
**             /players/thragor/guildobj will save the reports to
**             /log/rep/thragor, /d/shadows/guildobj will save the reports
**             to /log/rep/shadows
**
** cmd_gmail - Command for mailing all guildmembers
**
** In the init of the guild-object you must call 'add_false_cmds()'!!!
**
** Furthermore the skills are handled inside this object, i. e. using
** them and advancing them.
*/

#include <config.h>    // MASTER
#include <wizlevels.h> // IS_LEARNER
#include <rooms.h>
#include <moving.h>    // M_TELEPORT
#include <properties.h> //P_INVIS
#include <magia.h>
inherit "/std/equipment";

private static string owner,guild;
private static object guildob;

int QuerySize() {
	return 0;
}
public int IdGuildobject()
// With this function the guildobject identifies itself as guildobject.
{
  return 1;
}

public string SetGuild(string fn)
// Set the filename of the guild
{
  return guild = fn;
}

public string QueryGuild()
{
  return guild;
}

public string SetOwner(string pl)
// Set the owner of this guildobject
{
  return owner = pl;
}

public string QueryOwner()
{
  return owner;
}

public int LoadGuild()
// Load the guild and put the objectpointer to the guild into <guildob>
{
  string err;
  if (guildob) return 1;
  if (!guild) return 0;
  if (err = catch(guildob = load_object(guild)))
    {
      MASTER->runtime_error("No se puede cargar el gremio: "+err,guild,
                            object_name(TO));
      return 0;
    }
  return 1;
}

public object QueryGuildObject()
// Get the object-pointer of the guild this guildobject belongs to
{
  LoadGuild();
  return guildob;
}

public object *guild_users()
// return an array of all members currently online
{
  if (!LoadGuild()) return 0;
  return filter(users(),symbol_function("is_member",guildob));
}

public varargs int check_owner(object pl,int silent_force)
// check if the player is thw owner of this guildobject
// silent_force is only used when a player leaves the guild. In
// this case even a wizard will loose the guildobject (force)
// and the message won't be printed (silent).
{
  pl = pl||environment();
  if (!pl) call_out(SF(check_owner),2,pl,silent_force);
  if (!query_once_interactive(pl))
    {
      if (!owner) SetOwner(pl->QueryRealName()||pl->QueryShort());
      return 1;
    }
  if (!owner) SetOwner(getuid(pl));
  if (!LoadGuild()) return 1;
  if ((owner!=getuid(pl))
      ||(   (!IS_LEARNER(pl)||silent_force)
          && pl->QueryGuild()!=guildob->QueryGuildclass()
        ) )
    {
      if (!silent_force)
        tell_object(pl,"No tienes permiso para tener este objeto de gremio.\n");
      TO->remove();
      return 0;
    }
  return 1;
}

protected string who_list()
// return the whole guild-who list
{
  object *obs;
  string msg;
  int i;
  LoadGuild();
  obs=guild_users();
  msg="";
  for (i=0; i<sizeof(obs); i++)
  {
    if (!obs[i]->Query(P_INVIS))
    {
      msg+="  "+capitalize(obs[i]->QueryRealName())+" "+obs[i]->QueryTitle();
      msg+=" ["+capitalize(obs[i]->QueryRace()||"")+", "+obs[i]->QueryLevel()+"]";
      if (guildob->is_creator(obs[i])) msg+=" - Creador -\n";
      else if (guildob->is_leader(obs[i])) msg+=" - Líder -\n";
      else msg+="\n";
    }
    else
    {
      if (IS_LEARNER(TP))
      {
        msg+="  ("+capitalize(obs[i]->QueryRealName())+")";
        msg+=" ["+capitalize(obs[i]->QueryRace()||"")+", "+obs[i]->QueryLevel()+"]";
        if (guildob->is_creator(obs[i])) msg+=" - Creador -\n";
        else if (guildob->is_leader(obs[i])) msg+=" - Líder -\n";
        else msg+="\n";
      }
    }
  }
  return msg;
  //implode(map(guild_users(),SF(who_line))-({""}),"\n")+"\n";
}

public int cmd_gwho(string arg)
// the action "gwho"
{
  if (!TP) return 0;
/*
  if (arg)
    return notify_fail("Pon sólo 'gquien'.\n",NOTIFY_NOT_OBJ),0;
*/
  STR->smore(who_list(),TP->QueryPageSize());
  return 1;
}

public int cmd_gtp()
// the action "gtp"
{
  int tport;
  object env;
  if (!TP) return 0;
  if (!LoadGuild())
    return notify_fail("No puedo obtener los datos del gremio.\n",NOTIFY_NOT_OBJ),0;
  if (!guildob->is_leader(TP))
    return notify_fail("Sólo un Lider de Gremio puede usar esta habilidad.\n",NOTIFY_NOT_VALID),0;
  if (sizeof((TP->QueryEnemies()||({}))-({0})))
    return notify_fail("No puedes hacer esto en un combate.\n",
		       NOTIFY_NOT_VALID),0;
  if (   !(env = environment(TP))
      || env->QueryTPort()&TPORT_OUT==0
    )
  // we need the object_name/blueprint check, because we have to ensure,
  // that the room still exists if we move the player back.
    return notify_fail("No puedes hacer esto aqui.\n",
		       NOTIFY_NOT_VALID),0;
  if (env==guildob)
    return notify_fail("Ya estás en el gremio.\n",NOTIFY_NOT_VALID),0;
  tport = guildob->QueryTPort();
  guildob->SetTPort(TPORT_IN);
  TP->move(guildob,M_TELEPORT);
  guildob->SetTPort(tport);
  write("Llegas al gremio.\n");
  return 1;
}
//[w] Quitado porque ahora todos los objetos son auto_object()
// Vuelto a poner porque NO tiene que ver con los auto_object (ver comentario
// tras la cabecera de la funcion...

public mixed QueryAutoObject()
// You may modify this to save the data of the player to its
// /save-file or to save them to a file. But it always should
// return a value different from 0, otherwise the object is
// not autoloading
{
  return 1;
}

//[w] Quitado, total, todos los objetos son auto_object()
//[n] Referirse a lo anterior y a esas 8 lineas que hay aki debajo...

public mixed SetAutoObject(mixed values)
// You may modify this to load the data of the player from its
// savefile. The data will be given in <values> if saved sometime
// before. Or you may load the data from the player from an own
// savefile.
// But you should always call 'check_owner(TP)' in this
// function, to ensure, that the user has the right to use this
// tool. (SetAutoObject is called after the 'create'-function)
{
  check_owner(environment()||TP);
  return 1;
}

public void add_false_cmds()
{
  // obsolete
}

protected void smart_log(string what,string str)
{
  string creat;
  string *names;
  names = explode(object_name(),"/");
  if (sizeof(names)>1)
    {
      creat = names[2];
      log_file("rep/"+creat, ctime()+" G"+what+" from "+getuid(TP)+
               " in "+object_name(environment(TP))+":\n"
               "Reporting Object: "+object_name()+"\n"+str+"\n");
    }
  log_file("rep/"+what,ctime()+" "+getuid(TP)+" in "
                     +object_name(environment(TP))+":\n"
           "Reporting Object: "+object_name()+"\n"+str+"\n");
}

public int cmd_gbug(string str)
{
  if (!str || str == "")
    {
      write("Introduce la linea de informe: ");
      input_to("bug2");
      return 1;
    }
  smart_log("BUGS",str);
  write("Gracias por tu colaboración. En breve comprobaremos el bug del gremio.\n");
  return 1;
}

public void bug2(string str)
{
  if (!str || str == "")
    {
      write("Bug Cancelado.\n");
      return;
    }
  smart_log("BUGS",str);
  write("Gracias por tu colaboración. En breve comprobaremos el bug del gremio.\n");
}

public int cmd_gtypo(string str)
{
  if (!str || str == "")
    {
      write("Introduce la línea de informe: ");
      input_to("typo2");
      return 1;
    }
  smart_log("TYPO",str);
  write("Gracias por tu colaboración. En breve comprobaremos el typo del gremio.\n");
  return 1;
}

public void typo2(string str)
{
  if (!str || str == "")
    {
      write("Typo Cancelado.\n");
      return;
    }
  smart_log("TYPO",str);
  write("Gracias por tu colaboración. En breve comprobaremos el typo del gremio.\n");
}

public int cmd_gidea(string str)
{
  if (!str || str == "")
    {
      write("Introduce la línea de informe: ");
      input_to("idea2");
      return 1;
    }
  smart_log("IDEA",str);
  write("Tu idea será estudiada. Gracias por colaborar.\n");
  return 1;
}

public void idea2(string str)
{
  if (!str || str == "")
    {
      write("Idea Cancelada.\n");
      return;
    }
  smart_log("IDEA",str);
  write("Tu idea será estudiada. Gracias por colaborar.\n");
}

int cmd_ghelp()
{
  write("Comandos del gremio\n");
  write("-------------------\n");
  write("  ggritar: Grita algo a todos los miembros del gremio.\n");
  write("  gquien:  Muestra una lista de los miembros del gremio conectados.\n");
  write("  gtp:     Te transporta al gremio. Solo para los líderes de gremio.\n");
  write("  gbug:    Indica un bug en el funcionamiento del gremio.\n");
  write("  gtypo:   Indica un typo en el gremio.\n");
  write("  gidea:   Indica una idea para el funcionamiento del gremio.\n");
  write("  gayuda:  Esta ayuda.\n");
  return 1;
}

init()
{
  seteuid(getuid(TP));
  add_action("cmd_gwho", "gquien");
  add_action("cmd_gtp", "gtp");
  add_action("cmd_gbug", "gbug");
  add_action("cmd_gtypo", "gtypo");
  add_action("cmd_gidea", "gidea");
  add_action("cmd_ghelp", "gayuda");
}
