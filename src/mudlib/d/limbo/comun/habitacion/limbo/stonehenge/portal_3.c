/*
DESCRIPCION  : Portal no utilizado en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_3.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_vacio");

create() {
  muro="interior";
  ::create();
  AddExit("noroeste",STONE("portal_1"));
  AddExit("norte",STONE("portal_2"));
  AddExit("este",STONE("portal_draconiano"));
  AddExit("sudeste",STONE("st_entrada"));
  AddExit("sur",STONE("st_agua"));
  //AddExit("portal",SF(portal));
}
