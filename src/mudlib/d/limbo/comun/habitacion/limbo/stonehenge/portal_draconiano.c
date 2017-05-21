/*
DESCRIPCION  : Portal de los draconianos en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_draconiano.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit STONE("portal_tipo");

create() {
  destino="/d/simauria/comun/habitacion/marhalt/nandor/sendero4";
  raza="draconiano";
  newbiehome=STONE("portal_draconiano");
  muro="exterior";
  ::create();
  SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
  AddExit("noroeste",STONE("portal_2"));
  AddExit("oeste",STONE("portal_3"));
  AddExit("suroeste",STONE("st_agua"));
  AddExit("sur",STONE("st_entrada"));
  AddExit("portal",SF(portal));
}
