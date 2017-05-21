/*
DESCRIPCION  : camino a Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino09.c
MODIFICACION : 
08-02-99 [Angor] Creacion
16-09-07 [Angor] Typos y detalles
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("el camino a Gaddaro");
  SetIntLong(
    "Has llegado a un recodo en el camino junto a una gran peña. Desde aqui puedes "
    "contemplar la mayor parte del curso del Daraii: desde el lago Darum, al norte, "
    "hasta su union con el río Kuneii al suroeste de aqui. Sopla una agradable "
    "brisa desde el este.\n");

  AddDetail(({"penya","peña"}),
    "El camino gira aqui junto a una gran peña. Calculas que debe tener unos 5 o 6 "
    "metros de altura y un peso increible.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("norte",AZ_CAMINO("camino10"));
 AddExit("sudeste",AZ_CAMINO("camino08"));
}
