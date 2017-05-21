/*
DESCRIPCION  : puente sobre el Daraii
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino13.c
MODIFICACION :
09-02-99 [Angor@Simauria] Creacion
16-09-07 [Angor] Partes comunes a includes
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("un puente sobre el río Daraii");
  SetIntLong(
    "Estas sobre un viejo puente de piedra que permite cruzar sobre el río Daraii. "
    "El puente esta desgastado por el paso de las pesadas carretas que van y vienen "
    "del pueblo de Gaddaro que ves al nordeste a los productivos campos que hay al "
    "oeste de río y que forman la vega de Gaddaro. Bajo el puente, las aguas del "
    "Daraii descienden formando rápidos hacia el sur.\n");

  AddDetail(({"puente","viejo puente"}),
    "Es un un viejo puente de piedra que permite cruzar sobre el río Daraii, "
    "permitiendo asi ir desde el pueblo de Gaddaro, que queda justo al nordeste, "
    "hasta los campos de cultivo que hay al oeste y que forman la vega de Gaddaro. "
    "El puente esta desgastado por el continuo paso de pesadas carretas que vienen "
    "desde la vega, pero parece bastante resistente.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("oeste",AZ_CAMINO("camino14"));
 AddExit("este",AZ_CAMINO("camino12"));
}
