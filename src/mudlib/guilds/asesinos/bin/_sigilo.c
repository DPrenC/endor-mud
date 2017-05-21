/*
  ??-10-02 [Nyh] Arreglo el que no te canses con el sigilo.
  		 Hacer sigilo costara 2 TP en vez de 1 que cuesta andar normal
  		 Primero hago el chekeo de si tiene 2 o mas y luego resto solo
  		 1 porque luego al moverse resto el otro (esto lo hago porque
  		 si falla al moverse en silencio usa la funcion de moverse
  		 normal y alli le kitan automaticamante 1 TP)
*/

#include <moving.h>
#include <wizlevels.h>
#include "/guilds/asesinos/path.h"
#include <rooms.h>
#include <door.h>
#define COMMAND_NAME	HAB_SIGILO
#define MANA_COST	MANA_SIGILO

#define NORMAL_EXITS ({"norte","sur","este","oeste","nordeste","noroeste","sudeste" ,"suroeste"})


int AddTP(object ob, int i) {
   if(i > ob->QueryMaxTP()) i=ob->QueryMaxTP();
   else if(ob->QueryTP() < 1) ob->SetTP(0);
   else ob->SetTP(ob->QueryTP() + i);
   return ob->QueryTP();
}

mixed main(string salida) {
int check, i, mov;
mapping exits;
object *all, ob, o, *ven, env, puerta;
string *allexits;
mixed destino;

   ven=({});
   ob=TP;

   if(ob->HasSkill(COMMAND_NAME) == -1)
      return notify_fail(W("No posees la habilidad 'sigilo'. Contacta con un wizard.\n")),0;

   if(!salida) return notify_fail(W("Uso:  sigilo <salida>\n"));

   if(ob->Fighting())
      return notify_fail(W("No puedes moverte en silencio mientras peleas!\n")),0;
//Parte nueva para el cansancio
  // if(!IS_WIZARD(ob)) {
      if( ob->QueryTP() < 2 ) return notify_fail( "Estás muy cansado para hacer eso.\n" ), 0;
      AddTP(ob,-1);
  // }

   exits=(env = environment(ob))->QueryExits();
   allexits=m_indices(exits);

  salida = environment(ob)->map_normal_exit(salida);
  if(member(allexits, salida) == -1) return notify_fail("La salida '"+salida+"' no existe.\n");

  destino=exits[salida];
  if (!(stringp(destino) || objectp(destino))) return notify_fail(W("No puedes moverte en silencio hacia allí.\n"));
  if ((puerta = exits[salida, EXIT_DOOR]) && puerta->QueryDoorState() == DOOR_CLOSED)
  {
    if (!ob->CanSee(env))
    {
      ob->command_me(salida); // para que se pegue una ostia contra la salida
      return notify_fail("No has sido muy sigilos" + ob->QueryGenderEndString() + " que digamos...\n");
    }
    return notify_fail(CAP(puerta->QueryShort(env)) + " te impide ir en esa dirección.\n");
  }
  seteuid(getuid());
  if (stringp(destino)) destino=find_object(destino)||load_object(destino);
  if (!destino) return notify_fail("No puedes moverte en silencio hacia allí.\n");

  if (NO_MANA(ob)) return notify_fail("No tienes suficientes puntos de mana.\n");
  ob->AddSP(-MANA_COST);

  check=ob->UseSkill(COMMAND_NAME, ob->QueryGuildLevel(), 1);

  if(check <=0) { //fallo
    write("¡Haces demasiado ruido y todo el mundo te descubre!\n");
    ob->Set(P_HIDDEN,0);
    all=filter(all_inventory(environment(ob)),SF(living));
    foreach(o:all) o->init();
    command(salida,ob);
    return notify_fail(W("Fallas al intentar moverte en silencio.\n"));
  }
  //--
  else { //acierto
    all=filter(all_inventory(environment(ob))-({ob}),SF(living));
    for (i=sizeof(all);i--;) {
      if ( IS_LEARNER(o=all[i]) || (o->QueryInt()+o->QueryLevel())>check ) {
          ven += ({o});
          o->init();
      }
    } //for
    if (sizeof(ven)) write("Puede que alguien te haya oido moverte.\n");
    map(ven||({}),SF(tell_object),W("Notas como "+capitalize(ob->QueryName())+" intenta marcharse en silencio hacia "+salida+".\n"));
    mov=ob->move(destino, M_SILENT);
    //teoricamente aqui en el move se hacen los init no??
    switch(mov) {
      case ME_OK:
        if(member(NORMAL_EXITS, salida) == -1) {
          write(W("Te mueves en silencio hacia "+salida+".\n"));
          AddTP(ob,-1);
        }
        else {
          write(W("Te mueves en silencio hacia el "+salida+".\n"));
          ob->LookAfterMove();
          AddTP(ob,-1);
        }
      break;
      case ME_NO_LEAVE:
        write(W("!No te puedes mover de aquí!\n"));
        break;
      default:
        write(W("Alguna extraña razón no te deja ir hacia allí.\n"));
        break;
    }
    //ahora chekeo en el destino si alguien le oye y si se puede volver a esconder...
    all=filter(all_inventory(environment(ob))-({ob}),SF(living));
    for (i=sizeof(all);i--;) {
      if ( IS_LEARNER(o=all[i]) || (o->QueryInt()+o->QueryLevel())>check ) {
          ven += ({o});
          //o->init(); ya se ha hecho en el move?
      }
    } //for
    if (sizeof(ven)) write("Puede que alguien te haya oido llegar.\n");
    map(ven||({}),SF(tell_object),W("Notas como "+capitalize(ob->QueryName())+" intenta entrar en silencio.\n"));
    //y ahora si se puede volver a esconder, solo pueden verle los que le hayan oido
    if (ob->Query(P_HIDDEN)) ob->fhide(ven,1);
  } //else de acierto
  return 1;
}
