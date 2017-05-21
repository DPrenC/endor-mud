/*
DESCRIPCION  : Portal no utilizado en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_0.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_vacio");

create() {
  muro="exterior";
  ::create();
  SetIntNoise("Se oyen el ruido de las olas en los acantilados del oeste de la isla.\n");
  AddExit("nordeste",STONE("portal_elfo"));
  AddExit("este",STONE("portal_elfo_oscuro"));
  AddExit("sur",STONE("portal_troll"));
  AddExit("suroeste",STONE("portal_gigante"));
}
