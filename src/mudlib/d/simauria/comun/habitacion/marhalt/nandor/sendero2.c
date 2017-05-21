#include <mud.h>
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
Set(P_INT_SHORT,"un sendero");
SetIntLong(
"Te encuentras rodeado de tres edificaciones de madera. Hacia el este hay "
"una pequenya granja. Al norte encuentras un gran edificio de color rojo "
"donde se almacena el grano. Y hacia el sur se encuentra la cuadra donde "
"se guardan los animales. Puedes ver un molino de agua hacia el suroeste.\n");

SetIndoors(0);
SetIntNoise("Oyes ruidos de animales hacia el sur.\n");
SetIntSmell("Varios olores se confunden en el ambiente. Comida, animales y grano "
"confunden tus sentidos.\n");
SetLocate("nandor");

AddDetail(({"granja","pequenya granja","casa"}),
"Es una casa de madera con una altura de dos pisos.\n");
AddDetail(({"cuadra"}),
"Un enorme edificio de madera donde se guardan los animales.\n");
AddDetail(({"granero"}),
"Una gran construccion de madera para almacenar el grano.\n");

AddExit("norte","./granja/granero");
AddExit("sur","./granja/cuadra");
AddExit("sudeste","./sendero1");
}
