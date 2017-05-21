/*
   ##################################################################
   ## sim_room.c : Habitacion estandard para Simauria.             ##
   ## Creacion : 31/10/97. [n] Nemesis (nemesis@simauria.upv.es)   ##
   ##                      [m] Mirill (mirill@simauria.upv.es)     ##
   ## Modificacion : 12/10/98 [n] POR FIN el tiempo sale solamente ##
   ##                             donde tiene que salir.           ##
   ##################################################################
*/

#include "../path.h"

inherit ROOM;


create()
{
  ::create();
 SetIntShort("algún lugar en Simauria");
  SetIntLong("Estas en alguna parte del vasto dominio de Simauria.\n");
  SetLocate("Simauria");
  SetIntNoise("No oyes nada en especial.\n");
  SetIntSmell("No hueles nada en especial.\n");

  SetClimateServer(SERVER);
}
