/***
fichero: /guilds/guardabosques/train/montanya.c
30/08/2004. Kastwey@simauria. Puestos los mensajes de salida para las acciones del player.
31/08/2004. Añadida la función allow_enter, para evitar que los conjus usen la puerta
dimensional.
***/

#include "path.h"

inherit TRAIN_BASE;

#define NO_RASTREO 1
#define SI_RASTREO 4
#define TOTAL_RASTREO 30
#define RASTREO "_rastreo"
#define caminos ({"noroeste", "suroeste", "oeste"})


int cmd_rastrear(string str)
{
  int perc;

  if (TP->Query(RASTREO)>TOTAL_RASTREO)
  {
    write("¡Por fin has conseguido llegar a la ladera!\n");
    tell_room(TRAIN + "ladera",W(capitalize(TP->QueryName()) + " llega desde la montaña.\n"));
    TP->move(TRAIN+"ladera");
    return 1;
  }

  if (query_verb()=="rastrear")
    write("Rastreas la zona buscando algo que te indique la bajada más rápida.\n");
say(W(capitalize(TP->QueryName()) + " se pone a rastrear en busca de un lugar por donde bajar.\n"),TP);

  if (query_verb()=="rastrear")
    perc=TP->UseSkill(HAB_RASTREAR);
  else perc=0;

  if (perc<1)
  {
    write(W("Escoges el camino que va hacia el "+
    	(query_verb()=="rastrear"?caminos[random(sizeof(caminos)-1)]:query_verb())+" a la espera de que sea el "
    	"adecuado.\n"));
    TP->Set(RASTREO, TP->Query(RASTREO)+NO_RASTREO);
    return 1;
  }
  write(W("El camino que desciende hacia el "+
  	(query_verb()=="rastrear"?caminos[random(sizeof(caminos)-1)]:query_verb())+
  	" te parece el más adecuado.\n"));

  TP->Set(RASTREO, TP->Query(RASTREO)+SI_RASTREO);
  // write(TO->GetIntLong(TP->QueryBrief()));

  return 1;
}

init()
{
  ::init();

  if (TP->Query(RASTREO))
    SetIntShort("la bajada de la ladera");
    SetIntLong(W("Estás bajando por la ladera de la montaña. Podrías volver "
  	"a subir a la cima pero no tienes excesivas ganas, por lo que tan "
  	"sólo tienes un camino: hacia abajo. Puedes rastrear la zona para "
  	"encontrar el camino más directo.\n"));
}
create()
{
  ::create();

  SetIntShort("en la cima de la montaña");
  SetIntLong(W("Estás en la cima de la montaña. Ves varios caminos que al "
  	"parecer descienden, aunque es posible que sólo uno de ellos te "
  	"lleve abajo. Podrías rastrear la zona para buscar el camino más "
  	"adecuado.\n"));

  AddExit(caminos, SF(cmd_rastrear));
  AddRoomCmd("rastrear", SF(cmd_rastrear));
}
