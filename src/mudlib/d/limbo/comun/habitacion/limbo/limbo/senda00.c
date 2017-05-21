/*
DESCRIPCION  : Camino al oeste del pueblo
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/senda00.c
MODIFICACION : 15-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino al oeste del pueblo");
  SetIntLong(
"Este camino de tierra abandona el poblado de pescadores por el oeste avanzando "
"hacia la abrupta costa oeste de la isla. El camino asciende hacia el noroeste "
"para poder superar una loma y llegar esta costa. Al este de aquí se halla la "
"plaza central del pueblo.\n");

SetIntNoise("Oyes a las olas chocar contra el puerto a lo lejos.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("este",LIMBO("calle01"));
AddExit("noroeste",LIMBO("senda01"));
AddItem(HERBS("hierba_curativa"));
}
