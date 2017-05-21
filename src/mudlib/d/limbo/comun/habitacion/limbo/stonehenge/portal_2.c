/*
DESCRIPCION  : Portal no utilizado en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_2.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_vacio");

create() {
  muro="exterior";
  ::create();
  AddExit("oeste",STONE("portal_1"));
  AddExit("noroeste",STONE("portal_humano"));
  AddExit("sudeste",STONE("portal_draconiano"));
  AddExit("sur",STONE("portal_3"));
  //AddExit("portal",SF(portal));
}
