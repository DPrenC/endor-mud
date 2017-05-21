/*
DESCRIPCION  : Camino al oeste del pueblo
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/senda01.c
MODIFICACION : 15-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino al oeste del pueblo");
  SetIntLong(
"Has llegado a lo alto de la loma. Desde aquí puedes observar como hacia el "
"oeste el camino desciende serpentenado entre penyascos hasta una pequeña y "
"solitaria cala en la costa oeste de la isla rodeada por altos acantilados. "
"Hacia el sudeste el camino desciende hacia el poblado de pescadores.\n");

SetIntNoise("Oyes a las olas chocar a lo lejos.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("oeste",LIMBO("cala00"));
AddExit("sudeste",LIMBO("senda00"));
AddItem(PNJ("gorrion"), REFRESH_DESTRUCT, 1);
}
