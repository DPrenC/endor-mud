/*
DESCRIPCION  : Portal de los gigantes en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_gigante.c
MODIFICACION :
23-01-98 [angor] Creacion.
29-10-98 [woo] Modificado el path del destino.
29-10-98 [angor] Remodificado el path del destino: Woo, los mandabas al mismo
         sitio que lo kainoaks y luego el monolito no los dejaba volver (era
	 el monolito de los kainoaks)
15-02-00 [Angor] wrap
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/akallab/comun/habitacion/akallab/zarkam/camino/cc_11";
  raza="gigante";
  newbiehome=STONE("portal_gigante");
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
  AddExit("nordeste",STONE("portal_0"));
  AddExit("este",STONE("portal_troll"));
  AddExit("sudeste",STONE("st_fuego"));
  AddExit("sur",STONE("portal_orco"));
  AddExit("portal",SF(portal));
}
