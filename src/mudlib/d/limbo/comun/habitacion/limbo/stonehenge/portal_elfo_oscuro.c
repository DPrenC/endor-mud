/*
DESCRIPCION  : Portal de los elfo oscuros en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_elfo_oscuro.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  //destino="/d/akallab/comun/habitacion/akallab/zarkam/cementerio/tumba00";
  destino="/d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_10";
  raza="elfo-oscuro";
  newbiehome=STONE("portal_elfo_oscuro");
  muro="interior";
  ::create();
  SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
  AddExit("nordeste",STONE("portal_medio_elfo"));
  AddExit("norte",STONE("portal_elfo"));
  AddExit("oeste",STONE("portal_0"));
  AddExit("suroeste",STONE("portal_troll"));
  AddExit("este",STONE("st_aire"));
  AddExit("portal",SF(portal));
}
