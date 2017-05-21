/*
DESCRIPCION  : celda de un guardia del 'arbol de la vida'

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
"Estás en una habitación pequeña, parece la garita de algún guardia. No\n"
"hay mobiliario, tan sólo un banco apoyado contra la pared del fondo. Al\n"
"igual que en el resto del árbol, tanto las paredes como el techo están\n"
"formadas con la corteza del mismo. La poca luz que tiene la estancia pro-\n"
"viene de una espiral fosforescente colgada encima del banco y que brilla.\n"
);



AddDetail (({"banco"}),
"Ves un banco normal de madera, pero cuando te aproxinas\n"
"un poco para observarlo con mas detenimiento, ves que en\n"
"realidad esta tallado en la pared.\n"
);


AddDetail (({"espirales","luz","fosforescentes"}),
"Ves las espirales fosforescentes:\n"
"             _____________       _____\n"
"	     / ________    \     / ___ \\n"
"           / /	 _____ \    \   / /___\ \\n"
"          | /  /  \  \ |    | | |    || |\n"
"          | |  \__/  | |    | |  \__/ | |\n"
"           \ \______/ /      \ \_____/ /\n"
"            \________/        \_______/\n"
"\n"
"\n"
"Las espirales son uno de los sistemas mas antiguos\n"
"empleados por los elfos para iluminar las habitaciones\n"
"del 'arbol de la vida'. Estan hechas con algun derivado\n"
"del fosforo, aunque hay quien asegura que lo que en\n"
"verdad las ilumina es la presencia de algun tipo de\n"
"magia.\n"
);


SetIntBright(20);

SetIntNoise(
"Te parece escuchar el sonido de unos pasos militares\n"
"patrullando por la estancia.\n"
);


SetIntSmell(
"Percibes el olor a madera y savia\n"
);


SetLocate("Arbol");

SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("sur",TABASE("pasillo3"));



}