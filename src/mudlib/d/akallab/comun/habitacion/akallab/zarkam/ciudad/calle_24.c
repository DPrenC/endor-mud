/*
DESCRIPCION : junto a la puerta norte
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_24.c
MODIFICACION: 12-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

int ir_torre();

create() {
 ::create();
 SetIntShort("una calle junto a la muralla norte");
 SetIntLong(
     "Te hallas en una calle secundaria que avanza junto a la muralla de la ciudad. Al "
     "norte de aqui se halla una de las dos torres que forman la entrada a Zarkam. "
     "Supones que es alli donde se encuentran los engranajes y mecanismos que mueven "
     "las pesadas puertas de la ciudad. La puerta de la torre esta cerrada.\n");

  AddDetail(({"torre"}),
     "Es una inmensa torre de piedra. Junto con otra igual que se halla mas al oeste "
     "forman la entrada norte a esta ciudad.\n");

  SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("oeste",Z_CIUDAD("calle_05"));
  AddExit("este",Z_CIUDAD("calle_25"));
  AddExit("norte",SF(ir_torre));
}

int ir_torre() {
  write("La puerta de la torre esta cerrada. Tras forcejear un rato con ella no "
 "consigues que se abra.\n");

 say(capitalize(TP->QueryName())
 +" trata de abrir la puerta de la torre del este, pero tras forcejear "
  "un rato con ella no lo consigue.\n",TP);
 return 1;
}

