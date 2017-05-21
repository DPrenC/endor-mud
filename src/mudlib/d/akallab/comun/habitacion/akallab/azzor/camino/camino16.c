/*
DESCRIPCION  : en la vega de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino16.c
09-02-99 [Angor] Creacion
16-09-07 [Angor] Partes comunes a includes
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("la vega de Gaddaro");
  SetIntLong(
  "A tu alrededor se extienden los campos de cultivo de la vega de Gaddaro, el "
  "pueblo que puedes ver lejos al nordeste al otro lado del lago. El camino en "
  "que estas cruza estos campos hacia el nordeste, donde cruza el río Daraii. "
  "Al suroeste de aqui, el camino se adentra en el extenso y sombrio bosque de "
  "Talek.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("este",AZ_CAMINO("camino15"));
 AddExit("suroeste",BOSQUE_TALEK("camino20"));
}
