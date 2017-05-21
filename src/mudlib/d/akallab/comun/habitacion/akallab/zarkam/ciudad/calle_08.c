/*
DESCRIPCION : frente al establo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_08.c
MODIFICACION: 14-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("una calle junto a la muralla sur");
 SetIntLong(
     "La calle continua avanzando junto a la muralla sur de la ciudad de Zarkam. Al "
     "suroeste de aqui se alza una de las dos altas torres que forman la puerta sur de "
     "la ciudad. El establo donde la guardia de la entrada guarda sus caballos se "
     "encuentra al sur de aqui. Oyes como relinchan los caballos.\n");

  AddDetail(({"torre"}),
     "Es una inmensa torre de piedra. Junto con otra igual que se halla mas al oeste "
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

  AddExit("oeste",Z_CIUDAD("calle_07"));
  //AddExit("este",Z_CIUDAD("calle_07"));
  AddExit("sur",Z_CIUDAD("establo0"));
}
