/*
DESCRIPCION  : pequenya cala en la costa oeste
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/cala00.c
MODIFICACION : 15-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("una pequeña cala en la costa oeste");
  SetIntLong(
"Encajonada entre dos altos acantilados, esta pequeña cala es uno de los pocos "
"lugares de la abrupta costa oeste de la isla Limbo donde se puede llegar al mar. "
"Las olas llegan mansamente a la orilla de la playa tras haber perdido toda su "
"fuerza al chocar con las rocas. Un camino asciende serpenteando hacia el este de "
"la isla.\n");

SetIntNoise("Oyes a las olas chocar en las rocas.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("este",LIMBO("senda01"));
}
