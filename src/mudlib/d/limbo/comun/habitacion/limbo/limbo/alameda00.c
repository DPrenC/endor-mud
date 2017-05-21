/*
DESCRIPCION  : Paseo de la Alameda
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/alameda00.c
MODIFICACION : 31-01-98 [angor] Creacion.
               11-10-99 [Woo] Toqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetIntShort("el Paseo de la Alameda");
  SetIntLong(
"Te encuentras en el Paseo de la Alameda. Observas como al noroeste comienza "
"la zona de bosque que puebla gran parte de la isla Limbo. Sin embargo aquí el "
"paisaje esta formado por praderas verdes y los únicos árboles son los altos "
"alamos que flanquean el camino.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"paseo de la alameda","paseo","alameda","Alameda"}),
  "Es un camino que conduce desde el Camino del Sur hasta los acantilados de la "
  "costa sudeste de la isla Limbo, zona en la que se halla el Templo de Asthar. "
  "El camino en si está recubierto de una fina grava y esta flanqueado por dos "
  "largas filas de altos alamos. Las ramas de estos esbeltos árboles se mueven "
  "suavemente con la brisa que sube desde la costa.\n");

 SetIntNoise("Oyes el murmullo de la brisa entre las ramas de los árboles.\n");
 SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
 SetLocate("isla Limbo");

 AddExit("oeste",LIMBO("camino12"));
 AddExit("este",LIMBO("alameda01"));

 AddItem(HERBS("seta_saciante"), REFRESH_REMOVE);

SetIndoors(0);
}

