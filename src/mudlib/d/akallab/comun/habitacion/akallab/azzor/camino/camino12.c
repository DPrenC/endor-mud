/*
DESCRIPCION  : Junto al molino de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino12.c
MODIFICACION :
18-02-99 [Angor@Simauria] Creacion
16-09-07 [Angor] Partes comunes a includes
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetPreIntShort("junto a");
  SetIntShort("un molino");
  SetIntLong(
    "Te encuentras junto al puente que permite cruzar el río sobre el río Daraii. "
    "Observas como el río baja rápido desde el lago Darum, al norte, hacia el sur "
    "donde se une con el Kuneii. Al sur de aquí y junto al río se halla un molino "
    "donde los habitantes de Gaddaro muelen el trigo que cultivan en los campos de "
    "la vega que ves al otro lado del río.\n");

  AddDetail(({"molino"}),"Es el edificio que queda al sur de aqui.\n");

  AddDetail(({"puente","viejo puente"}),
    "Es un un viejo puente de piedra que permite cruzar sobre el río Daraii, "
    "permitiendo asi ir desde el pueblo de Gaddaro, que queda justo al nordeste, "
    "hasta los campos de cultivo que hay al oeste y que forman la vega de Gaddaro. "
    "El puente esta desgastado por el continuo paso de pesadas carretas que vienen "
    "desde la vega, pero parece bastante resistente.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("oeste",AZ_CAMINO("camino13"));
 AddExit("este",AZ_CAMINO("camino11"));
 AddExit("sur",GADDARO("molino"));
}
