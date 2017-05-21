/*
DESCRIPCION  : Portal de los logaths en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_logath.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/simauria/comun/habitacion/caminos/nandor-sherek/camino03";
  raza="logath";
  newbiehome=STONE("portal_logath");
  muro="exterior";
  ::create();
  SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
  AddExit("suroeste",STONE("portal_7"));
  AddExit("oeste",STONE("portal_4"));
  AddExit("noroeste",STONE("st_agua"));
  AddExit("norte",STONE("st_entrada"));
  AddExit("portal",SF(portal));
}
