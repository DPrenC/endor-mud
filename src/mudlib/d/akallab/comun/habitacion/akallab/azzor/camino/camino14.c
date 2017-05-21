/*
DESCRIPCION  : frente a la vega de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino14.c
MODIFICACION :
09-02-99 [Angor] Creacion
16-09-07 [Angor] Partes comunes a includes
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("la vega de Gaddaro");
  SetIntLong(
    "Frente a ti se extienden los campos de cultivo de la vega de Gaddaro al oeste. "
    "Estos campos regados por las aguas del lago Darum y del río Daraii son bastante "
    "productivos y la principal ocupacion de los habitantes del pueblo de Gaddaro "
    "que queda al nordeste, al otro lado del lago. Al este de aquí, un viejo puente "
    "de piedra permite cruzar sobre el río Daraii.\n");

  AddDetail(({"puente","viejo puente"}),
    "Es un un viejo puente de piedra que permite cruzar sobre el río Daraii,\n"
    "permitiendo asi ir desde el pueblo de Gaddaro, que queda justo al nordeste,\n"
    "hasta los campos de cultivo que hay al oeste y que forman la vega de Gaddaro.\n"
    "El puente esta desgastado por el continuo paso de pesadas carretas que vienen\n"
    "desde la vega, pero parece bastante resistente.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("suroeste",AZ_CAMINO("camino15"));
 AddExit("este",AZ_CAMINO("camino13"));
 AddExit("oeste",GADDARO("campo00"));
 AddExit("sur",GADDARO("campo01"));

}
