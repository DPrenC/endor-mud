/*
DESCRIPCION  :  Delante de la entrada del panteon, el fuego es una ilusion
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/ camino8.c
NOTAS:
CREACION :  ALura (Julio del 2000)
*/

#include "./path.h"
#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetPreIntShort("delante de");
SetIntShort("el panteón.");
SetIntLong(
" Tienes ante ti la entrada al panteón, delante de la cual se llergue una inmensa\n"
"columna de fuego que te impide el paso. La entrada al panteón está al sur.\n");

AddDetail (({"niebla"}),"  No hay restos de niebla.\n");

AddDetail (({"panteón"}),
"  Es una obra de arte gigantesca que destaca del cementerio porque no tiene la\n"
"misma fina y delicada estructura que el resto de lugares. Figuras como gárgolas\n"
"y otros horrorosos seres pueblan sus paredes.\n");
AddDetail (({"fuego","llamas","columna de fuego"}),
"  Las llamas salen sorprendentemente del suelo y sus lenguas de fuego abarcan\n"
"toda la entrada.\n");

AddDetail (({"entrada"}),
" No tiene puertas, aunque parece que antes sí tenia, y debian de ser grandes.\n");

SetIntNoise("  Oyes el fuerte crepitar de las llamas.\n");


SetIntSmell("  Que raro, no hueles a leña quemada.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(30);

AddItem("/d/lad-laurelin/comun/objeto/otro/tumba");

//AddExit("norte","bajada1");
AddExit("este","camino10");
AddExit("oeste","camino15");
AddExit("sur","camino7");
}