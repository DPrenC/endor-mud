/*
Por [F] Fran@simauria
        7 Nob, 1998: Las minas. pasillo subnivel 2.
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el túnel del Subnivel 2");
SetIntLong("Estás en el túnel del Subnivel 2,la luz es un poco escasa, pero "
"se ve\nbien. El tubo continúa por el techo.\n");

SetIntBright(40);
AddExit("este", MPISO2+"quinta2");
AddExit("oeste", MPISO2+"tercera2");
AddDetail(({"tubo"}),
"Es un tubo de ventilacion para que el aire fresco circule por toda "
"la mina.\n");

SetIntSmell(
"Hueles a tierra y a metal.\n");
SetIntNoise(
"Oyes golpes de pico a lo lejos.\n");
}