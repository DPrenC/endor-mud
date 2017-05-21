/*
DESCRIPCION : junto a la puerta norte
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_23.c
MODIFICACION: 12-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("una calle junto a la muralla norte");
 SetIntLong(
     "Te hallas en una calle secundaria que avanza junto a la muralla de la ciudad. Al "
     "norte de aqui se halla una de las dos torres que forman la entrada a Zarkam. "
     "Oyes el relinchar de caballos cerca de aqui.\n");

  AddDetail(({"torre"}),
     "Es una inmensa torre de piedra. Junto con otra igual que se halla mas al este "
     "forman la entrada sur a esta ciudad.\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege la ciudad rodeandola por completo. "
     "Dirias que como minimo tiene unos cinco metros de altura en las partes mas bajas "
     "y esta protegida con gruesas almenas. Sobre ella hay una pasarela por la que "
     "cada cierto tiempo ves pasar soldados fuertemente armados.\n");

  SetIntNoise("Se oye el relinchar de caballos.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("oeste",Z_CIUDAD("calle_22"));
  AddExit("este",Z_CIUDAD("calle_05"));
}
