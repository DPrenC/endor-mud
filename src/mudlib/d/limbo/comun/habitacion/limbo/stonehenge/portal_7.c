/*
DESCRIPCION  : Portal no utilizado en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_7.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_vacio");

create() {
  muro="exterior";
  ::create();
  AddExit("norte",STONE("portal_4"));
  AddExit("oeste",STONE("portal_6"));
  AddExit("suroeste",STONE("portal_kender"));
  AddExit("nordeste",STONE("portal_logath"));
  //AddExit("portal",SF(portal));
}
