/*
DESCRIPCION  : Portal no utilizado en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_6.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_vacio");

create() {
  muro="interior";
  ::create();
  AddExit("oeste",STONE("st_tierra"));
  AddExit("suroeste",STONE("portal_enano"));
  AddExit("sur",STONE("portal_kender"));
  AddExit("este",STONE("portal_7"));
  AddExit("nordeste",STONE("portal_4"));
  //AddExit("portal",SF(portal));
}
