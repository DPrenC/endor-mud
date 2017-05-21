/*
DESCRIPCION : cruce de calles junto a la puerta sur
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_09.c
MODIFICACION: 11-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

int ir_torre();

create() {
 ::create();
 SetIntShort("una calle junto a la muralla sur");
 SetIntLong(
     "Te hallas en una calle secundaria que avanza junto a la muralla de la ciudad. Al "
     "sur de aqui se halla una de las dos torres que forman la entrada a Zarkam. "
     "Supones que es alli donde se encuentran los engranajes y mecanismos que mueven "
     "las pesadas puertas de la ciudad. La puerta de la torre esta cerrada.\n");

  AddDetail(({"torre"}),
     "Es una inmensa torre de piedra. Junto con otra igual que se halla mas al este "
     "forman la entrada sur a esta ciudad.\n");

  SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("oeste",Z_CIUDAD("calle_10"));
  AddExit("este",Z_CIUDAD("calle_01"));
  AddExit("sur",SF(ir_torre));
}

int ir_torre() {
  write("La puerta de la torre esta cerrada. Tras forcejear un rato con ella no "
 "consigues que se abra.\n");

 say(capitalize(TP->QueryName())
 +" trata de abrir la puerta de la torre del del oeste, pero tras forcejear "
  "un rato con ella no lo consigue.\n",TP);
 return 1;
}

