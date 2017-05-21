/*
Por [F] Fran@simauria
        7 Nob, 1998: Las minas. pasillo subnivel 2.
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el subnivel 2");
SetIntLong("Estás en el subnivel 2, no hay lámparas, pero se ve con "
"la luz de las lámparas anteriores y las que hay mas adelante.\n"
"El tubo de ventilacion esta por el techo.\n");

SetIntBright(45);
AddExit("este", MPISO2+"tercera2");
AddExit("oeste", MPISO2+"primera2");
AddDetail(({"tubo","tubo de ventilacion"}),
"Es un de tubo de ventilacion para que el aire fresco circule por toda "
"la mina.\n");

SetIntSmell(
"Hueles a tierra y a metal.\n");
SetIntNoise(
"Oyes golpes de pico y algun que otro grito.\n");
}