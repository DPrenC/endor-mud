/*
DESCRIPCION  : camino a Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino11.c
MODIFICACION : 08-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("las afueras del pueblo de Gaddaro");
  SetIntLong(
    "Al norte de aquí se encuentra Gaddaro, un pequeño pueblo situado en la parte "
    "alta del valle. Este camino conduce desde Gaddaro hasta el lejano Camino del "
    "Este que cruza el valle. Un sendero parte hacia las productivas tierras de "
    "la vega de Gaddaro que queda al otro lado del río Darmaii. Justo "
    "al oeste de aquí, un puente permite cruzar este río.\n");

    AddDetail(({"puente"}),
       "El puente está al oeste de aquí.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("oeste",AZ_CAMINO("camino12"));
 AddExit("sudeste",AZ_CAMINO("camino10"));
 AddExit("norte",GADDARO("calle00"));
}
