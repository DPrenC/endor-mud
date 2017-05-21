/*
DESCRIPCION  : Portal de los kainoaks en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_kainoak.c
MODIFICACION : 23-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/akallab/comun/habitacion/akallab/zarkam/camino/cc_00";
  raza="kainoak";
  newbiehome=STONE("portal_kainoak");
  muro="interior";
  ::create();
  SetIntNoise("Se oyen el ruido de las olas en los acantilados del oeste de la isla.\n");
  AddExit("sudeste",STONE("portal_gnomo"));
  AddExit("sur",STONE("portal_5"));
  AddExit("oeste",STONE("portal_demonio"));
  AddExit("noroeste",STONE("portal_orco"));
  AddExit("norte",STONE("st_fuego"));
  AddExit("portal",SF(portal));
}
