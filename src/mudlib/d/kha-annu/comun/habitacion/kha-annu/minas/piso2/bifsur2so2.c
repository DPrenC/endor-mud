/*
Por [F] Fran@simauria
        15 oct 1999
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el subnivel 2");
SetIntLong("Estás en el subnivel 2, no hay lámparas, pero se ve "
"con la luz de una cámara que hay mas adelante.\n"
"El tubo continúa por el techo.\n");

SetIntBright(30);
AddExit("sur",MPISO2+"bifsur2socámara");
AddExit("nordeste",MPISO2+"bifsur2so");

AddDetail(({"tubo","especie de tubo"}),
"Es una especie de tubo de ventilacion para que el aire fresco circule por \
toda "
"la mina.\n");

SetIntSmell("Hueles a tierra y a metal.\n");
SetIntNoise("Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n");
}