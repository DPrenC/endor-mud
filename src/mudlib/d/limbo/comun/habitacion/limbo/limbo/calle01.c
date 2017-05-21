/*
DESCRIPCION  : Plaza central del pueblo de la isla Limbo
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/calle01.c
MODIFICACION : 13-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la plaza central del pueblo de la isla Limbo");
  SetIntLong(
"Te hallas en una pequeña explanada que hace las veces de plaza central de este "
"pueblo. Desde aquí observas como una calle continua hacia el sur hasta el puerto "
"y otra avanza hacia el oeste. Al norte de aquí se halla un edificio de piedra "
"que parece ser el ayuntamiento, y un rótulo indica que la casa que queda al este "
"es la fonda del 'Viejo Pescador'.\n");

AddDetail(({"puerto","muelle","barcas"}),
 "A lo lejos ves el puerto con barcas amarradas en su muelle. Deberias acercarte "
 "si quieres verlo con mas detalle.\n");

AddDetail(({"rotulo"}),
 "En la fachada de la fonda hay colgado un rótulo con el dibujo de un gran pez "
 "que sonrie. Bajo el, esta escrito el texto: fonda 'el pescado feliz'.\n");

SetIntNoise("Oyes el murmullo de la actividad en el pueblo.\n");
SetIntSmell("El olor del campo se confunde con el del mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("nordeste",LIMBO("calle00"));
AddExit("norte",LIMBO("ayuntamiento"));
AddExit("sur",LIMBO("calle03"));
AddExit("oeste",LIMBO("senda00"));
AddExit("este",LIMBO("fonda"));
}
