/*
DESCRIPCION  : Portal de los medio elfos en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_medio_elfo.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/lad-laurelin/comun/habitacion/atbalnin/bosque/bosque22";
  raza="medio-elfo";
  newbiehome=STONE("portal_medio_elfo");
  muro="exterior";
  ::create();
  SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
  AddExit("oeste",STONE("portal_elfo"));
  AddExit("suroeste",STONE("portal_elfo_oscuro"));
  AddExit("sur",STONE("st_aire"));
  AddExit("sudeste",STONE("portal_1"));
  AddExit("este",STONE("portal_humano"));
  AddExit("portal",SF(portal));
}
