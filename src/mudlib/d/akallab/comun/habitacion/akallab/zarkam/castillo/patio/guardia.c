/*
DESCRIPCION : caseta de la guardia en el patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio/guardia.c
MODIFICACION: 30-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("la caseta de guardias del castillo");
 SetIntLong(
   "Te hallas en el interior de la caseta adosada a la muralla. Aqui vive la guardia "
   "de soldados que controla la puerta de entrada al castillo. Es una habitacion de "
   "mediano tamanyo en cuyo fondo se encuentra una chimenea en la que arde un "
   "pequenyo fuego. Despues de hacer una guardia en las frias noches de esta zona, "
   "calentarse en el debe ser un una bendicion para los soldados. Al este, una "
   "puerta comunica con una de las torres de la muralla.\n");

AddDetail(({"fuego","chimenea"}),
   "Al fondo de la habitacion hay una chimenea en la que siempre arde un pequenyo "
   "fuego. Tras las frias guardias nocturnas, los soldados se reunen junto a el para "
   "calentarse un poco los doloridos huesos.\n");

AddDetail(({"puerta"}),"Conduce a la parte baja de la torre de la muralla.\n");

SetIntNoise("Las brasas del fuego crepitan lastimeramente.\n");
SetIntSmell("El aire es calido y agradable.\n");
SetLocate("castillo de Zarkam");
SetIndoors(1);
SetIntBright(50);

AddExit("este",Z_CASTILLO("muralla/torre23"));
AddExit("sur",Z_CASTILLO("patio/patio01"));

AddItem(PNJ("z_castillo/guardia"),REFRESH_DESTRUCT,3);
}
