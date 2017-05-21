/*
Por [F] Fran@simauria
        15 oct 1999
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el subnivel 2");
SetIntLong("Estás en el final de este túnel, no hay lámparas y esta un "
"poco oscuro.\n"
"El tubo se entierra en el suelo.\n");

SetIntBright(10);
AddExit("suroeste",MPISO2+"bifne222");
AddDetail(({"tubo","especie de tubo"}),
"Es una especie de tubo de ventilacion para que el aire fresco circule por \
toda "
"la mina, en este punto se entierra en el suelo.\n");

SetIntSmell("Hueles a tierra y a cerrado.\n");
SetIntNoise("Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n");
}