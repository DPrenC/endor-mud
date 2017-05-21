/*
Por [F] Fran@simauria
        25 Jul, 1998: Las minas. pasillo nivel 1.
        15 Oct 1999: remodelacion salida abajo.
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el pasillo Sur");
SetIntLong("Estás en el pasillo Sur del nivel uno, no hay lámparas, pero "
"se ve "
"con la luz de las lámparas anteriores y las que hay mas adelante.\n"
"El tubo continúa por el techo.\n");

SetIntBright(40);
AddExit("noroeste", MPISO1+"septima");
AddExit("sudeste", MPISO1+"bifso2");
AddExit("abajo", MPISO2+"sexta2");
AddDetail(({"tubo","especie de tubo"}),
"Es una especie de tubo de ventilacion para que el aire fresco circule por \
toda "
"la mina.\n");

SetIntSmell(
"Hueles a tierra y a metal.\n");
SetIntNoise(
"Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n");
}