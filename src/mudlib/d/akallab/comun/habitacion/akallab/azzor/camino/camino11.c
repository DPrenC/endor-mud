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
    "Al norte de aqu� se encuentra Gaddaro, un peque�o pueblo situado en la parte "
    "alta del valle. Este camino conduce desde Gaddaro hasta el lejano Camino del "
    "Este que cruza el valle. Un sendero parte hacia las productivas tierras de "
    "la vega de Gaddaro que queda al otro lado del r�o Darmaii. Justo "
    "al oeste de aqu�, un puente permite cruzar este r�o.\n");

    AddDetail(({"puente"}),
       "El puente est� al oeste de aqu�.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("oeste",AZ_CAMINO("camino12"));
 AddExit("sudeste",AZ_CAMINO("camino10"));
 AddExit("norte",GADDARO("calle00"));
}
