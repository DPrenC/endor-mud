/*
DESCRIPCION  : Portal no utilizado en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_1.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_vacio");

create() {
  muro="interior";
  ::create();
  AddExit("oeste",STONE("st_aire"));
  AddExit("noroeste",STONE("portal_medio_elfo"));
  AddExit("norte",STONE("portal_humano"));
  AddExit("este",STONE("portal_2"));
  AddExit("sudeste",STONE("portal_3"));
}
