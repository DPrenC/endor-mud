/*
DESCRIPCION  : Portal de los humanos en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_humano.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/simauria/comun/habitacion/marhalt/nandor/tiendas/iglesia";
  raza="humano";
  newbiehome=STONE("portal_humano");
  muro="exterior";
  ::create();
  SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
  AddExit("oeste",STONE("portal_medio_elfo"));
  AddExit("suroeste",STONE("st_aire"));
  AddExit("sur",STONE("portal_1"));
  AddExit("sudeste",STONE("portal_2"));
  AddExit("portal",SF(portal));
}
