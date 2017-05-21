/*
DESCRIPCION  : Portal de los enanos en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_enano.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/kha-annu/comun/habitacion/kha-annu/ciudad/ayuntamiento/porkha";
  raza="enano";
  newbiehome=STONE("portal_enano");
  muro="exterior";
  ::create();
  AddExit("oeste",STONE("portal_duende"));
  AddExit("noroeste",STONE("portal_gnomo"));
  AddExit("norte",STONE("st_tierra"));
  AddExit("nordeste",STONE("portal_6"));
  AddExit("este",STONE("portal_kender"));
  AddExit("portal",SF(portal));
}
