/*
DESCRIPCION  : Portal no utilizado en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_4.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_vacio");

create() {
  muro="interior";
  ::create();
  AddExit("suroeste",STONE("portal_6"));
  AddExit("sur",STONE("portal_7"));
  AddExit("este",STONE("portal_logath"));
  AddExit("nordeste",STONE("st_entrada"));
  AddExit("norte",STONE("st_agua"));
}
