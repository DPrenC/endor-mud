/*
DESCRIPCION  : camino a Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino10.c
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
    "El camino hacia el pueblo de Gaddaro prosigue su lento pero constante ascenso "
    "a medida que se acerca a este pueblo que ya observas al noroeste. Al oeste, "
    "ves el Daraii descendiendo hacia el sur, y más allá, la productivas tierras "
    "que forman la vega de Gaddaro.\n");

#include "geografia.ic"
#include "ambiente.ic"
  
 AddExit("sur",AZ_CAMINO("camino09"));
 AddExit("noroeste",AZ_CAMINO("camino11"));
}
