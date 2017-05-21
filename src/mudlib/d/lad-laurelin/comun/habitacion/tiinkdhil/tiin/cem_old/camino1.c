/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION :
*/

#include "./path.h"
#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("una bifurcación en el cementerio");
SetIntLong(
"  El camino gira aqui en dirección norte y llega hasta una pared cubierta de\n"
"enredaderas. El otro sendero lleva hacia el este y al surdeste se encuentra la\n"
"entrada al cementerio. La niebla empieza a ser algo mas espesa aqui, pero puedes\n"
"ver algunos matorrales secos junto a las lápidas.\n");

AddDetail(({"lapidas","sepulturas","tumbas","lápidas"}),
"  Todas las lapidas tienen una inscripcion con el nombre de quien yace en la\n"
"sepultura.\n");
AddDetail (({"niebla"}),
"  Cerca del suelo es espesa y apenas te deja ver la hierba que recubre todo\n"
"el cementerio,el resto se trata de una niebla mucho menos densa pero que aun\n"
"así te impide ver el final del camino.\n");
AddDetail (({"matorral","matorrales"}),
" No tienen nada de especial, son solo arbustos	secos. Tal vez en otra época\n"
"estarian llenos de vida para dar algo de color al visitante.\n");

SetIntNoise("  Se puede oir la suave brisa del viento,que mueve la hierba. Se oye\n"
"algo mas al fondo, cerca del camino,pero desde esta distancia no puedes saber bien\n"
"de que se trata.\n");
SetIntSmell("  Pese a ser un cementerio, mira por donde no tiene mal olor.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(20);

AddExit("norte","camino2");
AddExit("este","camino4");

}