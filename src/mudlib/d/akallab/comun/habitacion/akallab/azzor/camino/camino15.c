/*
DESCRIPCION  : en la vega de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino15.c
09-02-99 [Angor] Creacion
16-09-07 [Angor] Partes comunes a includes
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("la vega de Gaddaro");
  SetIntLong(
    "Te encuentras en el camino que atraviesa los campos de cultivo de la vega de "
    "Gaddaro. Los campos de la vega parecen bien cuidados y bastante productivos. "
    "Hacia el este, el camino se dirige hacia el río Daraii, y hacia el suroeste, "
    "hacia el extremo norte del inmenso bosque de Talek.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("nordeste",AZ_CAMINO("camino14"));
 AddExit("oeste",AZ_CAMINO("camino16"));
 AddExit("este",GADDARO("campo01"));
 AddExit("norte",GADDARO("campo00"));
}
