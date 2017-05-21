/*
DESCRIPCION  : celda de un guardia

FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/

MODIFICADO POR AVENGELYNE, LA MUJER FATAL
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("la celda de un guardia");
  SetIntLong(
"Estás en una estancia que, seguramente, antes serviría de celda de vigi-\n"
"lancia de algún guardia. Ahora está vacia tan sólo hay un banco de madera\n"
"apoyado en la pared, o quizás se encuentra tallado en la pared de la cel-\n"
"da.Tanto las paredes como el techo estan formados con la corteza del árbol.\n"
);



AddDetail (({"banco","silla"}),
"Ves un banco tallado en la corteza del arbol, es bastante\n"
"largo, de aproximadamente unos 2 metros de longitud\n"
"parece muy resistente.\n"
);



SetIntBright(20);
SetIntNoise(
"Te parece escuchar el sonido de unos pasos arrastrandose\n"
"por la tierra del suelo.\n"
);


SetIntSmell(
"Percibes el olor de tierra unido al de la madera.\n"
);

SetLocate("Arbol");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("este",TABASE("pasillo1"));

}