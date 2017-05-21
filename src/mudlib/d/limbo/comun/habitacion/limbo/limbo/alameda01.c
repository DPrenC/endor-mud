/*
DESCRIPCION  : Paseo de la Alameda
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/alameda01.c
MODIFICACION : 31-01-98 [angor] Creacion.
               11-10-99[Woo] Toqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetIntShort("el Paseo de la Alameda");
  SetIntLong(
"El Paseo de la Alameda continua avanzando perezosamente hacia la costa de "
"la isla Limbo entre praderas. El suave rumor de las ramas de los alamos que "
"flanquean el camino agitandose bajo el efecto de la brisa del mar y la "
"agradable temperatura del ambiente resultan casi adormecedores.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"paseo de la alameda","paseo","alameda","Alameda"}),
  "Es un camino que conduce desde el Camino del Sur hasta los acantilados de la "
  "costa sudeste de la isla Limbo, zona en la que se halla el Templo de Asthar. "
  "El camino en si está recubierto de una fina grava y esta flanqueado por dos "
  "largas filas de altos alamos. Las ramas de estos esbeltos arboles se mueven "
  "suavemente con la brisa que sube desde la costa.\n");

 SetIntNoise("Oyes el murmullo de la brisa entre las ramas de los árboles y a lo lejos el "
  "ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("oeste",LIMBO("alameda00"));
 AddExit("este",LIMBO("alameda02"));
}

