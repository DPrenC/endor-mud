/*
DESCRIPCION  : camino a Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino08.c
MODIFICACION : 08-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("el camino a Gaddaro");
  SetIntLong(
    "El camino que conduce al pueblo de Gaddaro comienza a ascender a medida que "
    "avanza hacia el noroeste del valle. La brisa mece las ramas de los altos robles "
    "que crecen junto al camino. Lejos al oeste puedes ver como el afluente Daraii "
    "se une con el río Kuneii, y mas alla, el bosque de Talek.\n");

  AddDetail(({"robles"}),
    "Por su tamaño dirias que deben llevar aquí desde tiempo inmemorial. Sus frondosas "
    "ramas dan buena sombra en los dias tórridos del verano.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("este",AZ_CAMINO("camino07"));
 AddExit("noroeste",AZ_CAMINO("camino09"));
}
