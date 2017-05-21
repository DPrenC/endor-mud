/*
DESCRIPCION  : Portal de los duendes en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_duende.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
 destino="/d/kha-annu/comun/habitacion/caminos/kha-kenton/kha-kenton20";
  raza="duende";
  newbiehome=STONE("portal_duende");
  muro="exterior";
  ::create();
  AddExit("noroeste",STONE("portal_5"));
  AddExit("norte",STONE("portal_gnomo"));
  AddExit("nordeste",STONE("st_tierra"));
  AddExit("este",STONE("portal_enano"));
  AddExit("portal",SF(portal));
}
