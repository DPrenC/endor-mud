/*
DESCRIPCION  : camino a Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino07.c
MODIFICACION :
05-02-99 [Angor] Creacion
16-09-07 [Angor] Partes comunes a includes
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("el camino a Gaddaro");
  SetIntLong(
    "Estás al principio del camino que conduce desde el Camino del Este, que cruza "
    "todo este valle y pasa justo al sudeste de aquí, hasta el pequeño pueblo de "
    "Gaddaro que queda lejos al noroeste. Al sur junto al cruce ves una fonda.\n");

  AddDetail(({"fonda"}),"Es el bajo edificio que se halla al sur de aquí.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("oeste",AZ_CAMINO("camino08"));
 AddExit("sudeste",AZ_CAMINO("camino06"));
}
