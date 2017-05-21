/*
DESCRIPCION  : Portal de los trolls en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_troll.c
MODIFICACION : 23-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/akallab/comun/habitacion/akallab/kuntz/cueva/monolito";
  raza="troll";
  newbiehome=STONE("portal_troll");
  muro="interior";
  ::create();
  SetIntNoise("Se oyen el ruido de las olas en los acantilados del oeste de la isla.\n");
  AddExit("nordeste",STONE("portal_elfo_oscuro"));
  AddExit("norte",STONE("portal_0"));
  AddExit("oeste",STONE("portal_gigante"));
  AddExit("suroeste",STONE("portal_orco"));
  AddExit("sur",STONE("st_fuego"));
  AddExit("portal",SF(portal));
}
