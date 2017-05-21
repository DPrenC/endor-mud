/*
Por [F] Fran@simauria
        15 oct 1999
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el subnivel 2");
SetIntLong("Est�s en el subnivel 2, no hay l�mparas, pero se ve "
"con la luz de las l�mparas anteriores y las que hay mas adelante.\n"
"El tubo contin�a por el techo.\n");

SetIntBright(40);
AddExit("este", MPISO2+"septima2");
AddExit("oeste", MPISO2+"quinta2");
AddExit("arriba", MPISO1+"bifso1");
AddDetail(({"tubo","especie de tubo"}),
"Es una especie de tubo de ventilacion para que el aire fresco circule por \
toda "
"la mina.\n");

SetIntSmell("Hueles a tierra y a metal.\n");
SetIntNoise("Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n");
}