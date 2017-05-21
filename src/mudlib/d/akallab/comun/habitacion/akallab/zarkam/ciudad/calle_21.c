/*
DESCRIPCION : en una calle de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_21.c
MODIFICACION: 18-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("una calle junto a la muralla norte");
  SetIntLong(
     "Te encuentras en la calle que hay junto a la muralla norte de la ciudad de "
     "Zarkam. Al suroeste de aqui comienzan los barrios bajos de esta ciudad, una "
     "zona donde se puede encontrar todo tipo de diversion y otras cosas... Es un "
     "lugar bastante conflictivo, especialmente por las noches, por lo que no es muy "
     "aconsejable aventurarse a solas en el. Oyes caballos relinchar cerca de aqui.\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege la ciudad rodeandola por completo. "
     "Dirias que como minimo tiene unos cinco metros de altura en las partes mas bajas "
     "y esta protegida con gruesas almenas. Sobre ella hay una pasarela por la que "
     "cada cierto tiempo ves pasar soldados fuertemente armados.\n");

  SetIntNoise("Se oye el relinchar de caballos.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  //AddExit("oeste",Z_CIUDAD("calle_35"));
  AddExit("este",Z_CIUDAD("calle_22"));
  AddExit("sur",Z_CIUDAD("calle_20"));
}
