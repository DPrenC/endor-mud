/*
DESCRIPCION  : Portal de los demonios en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_demonio.c
MODIFICACION : 23-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/akallab/comun/habitacion/akallab/zarkam/camino/c_mina06";
  raza="demonio";
  newbiehome=STONE("portal_demonio");
  muro="exterior";
  ::create();

  SetIntLong(QueryIntLong()+
  "Por el ruido de las olas, supones que el acantilado de la costa oeste de la isla "
  "no debe quedar lejos.\n");

  AddDetail(({"acantilado","acantilados"}),
  "Mirando al oeste a traves de los arcos de piedra de Stonehenge, observas "
  "como la loma acaba bruscamente en el acantilado que forma la costa oeste "
  "de la isla Limbo. Aunque desde aqui no se ve el acantilado directamente, "
  "oyes el ruido de las olas chocando furiosamente contra el.\n");

  SetIntNoise("Se oyen el ruido de las olas en los acantilados del oeste de la isla.\n");
  AddExit("norte",STONE("portal_orco"));
  AddExit("nordeste",STONE("st_fuego"));
  AddExit("este",STONE("portal_kainoak"));
  AddExit("sudeste",STONE("portal_5"));
  AddExit("portal",SF(portal));
}
