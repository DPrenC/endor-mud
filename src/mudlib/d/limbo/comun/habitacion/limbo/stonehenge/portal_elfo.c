/*
DESCRIPCION  : Portal de los elfos en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_elfo.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/lad-laurelin/comun/habitacion/atbalnin/bosque/bosque09";
  raza="elfo";
  newbiehome=STONE("portal_elfo");
  muro="exterior";
  ::create();
  SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
  AddExit("suroeste",STONE("portal_0"));
  AddExit("sur",STONE("portal_elfo_oscuro"));
  AddExit("sudeste",STONE("st_aire"));
  AddExit("este",STONE("portal_medio_elfo"));
  AddExit("portal",SF(portal));
}
