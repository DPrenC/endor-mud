/*
DESCRIPCION  : Portal de los orcos en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_orco.c
MODIFICACION :
22-01-98 [Angor] Creacion.
15-02-00 [Angor] wrap
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/akallab/comun/habitacion/akallab/zarkam/tienda/templo";
  raza="orco";
  newbiehome=STONE("portal_orco");
  muro="exterior";
  ::create();
  SetIntLong(QueryIntLong()+
  W("Por el ruido de las olas, supones que el acantilado de la costa oeste de "
    "la isla no debe quedar lejos.\n"));

  AddDetail(({"acantilado","acantilados"}),
  W("Mirando al oeste a traves de los arcos de piedra de Stonehenge, observas "
    "como la loma acaba bruscamente en el acantilado que forma la costa oeste "
    "de la isla Limbo. Aunque desde aqui no se ve el acantilado directamente, "
    "oyes el ruido de las olas chocando furiosamente contra el.\n"));
  SetIntNoise("Se oyen el ruido de las olas en los acantilados del oeste de la isla.\n");
  AddExit("norte",STONE("portal_gigante"));
  AddExit("nordeste",STONE("portal_troll"));
  AddExit("este",STONE("st_fuego"));
  AddExit("sudeste",STONE("portal_kainoak"));
  AddExit("sur",STONE("portal_demonio"));
  AddExit("portal",SF(portal));
}
