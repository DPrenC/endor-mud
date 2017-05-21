/*
DESCRIPCION  : Portal no utilizado en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_5.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_vacio");

create() {
  muro="exterior";
  ::create();
  SetIntNoise("Se oyen el ruido de las olas en los acantilados del oeste de la isla.\n");
  AddExit("noroeste",STONE("portal_demonio"));
  AddExit("norte",STONE("portal_kainoak"));
  AddExit("este",STONE("portal_gnomo"));
  AddExit("sudeste",STONE("portal_duende"));
}
