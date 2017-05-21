/*
DESCRIPCION  : Portal de los gnomos en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_gnomo.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/kha-annu/comun/habitacion/kha-annu/ciudad/ayuntamiento/porkha";
  raza="gnomo";
  newbiehome=STONE("portal_gnomo");
  muro="interior";
  ::create();
  AddExit("sudeste",STONE("portal_enano"));
  AddExit("sur",STONE("portal_duende"));
  AddExit("oeste",STONE("portal_5"));
  AddExit("noroeste",STONE("portal_kainoak"));
  AddExit("este",STONE("st_tierra"));
  AddExit("portal",SF(portal));
}
