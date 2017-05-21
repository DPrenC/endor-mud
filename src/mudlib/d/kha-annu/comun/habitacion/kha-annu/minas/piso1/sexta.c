/*
Por [F] Fran@simauria
        25 Jul, 1998: Las minas. pasillo nivel 1.
Hay que arreglar la salida de abajo y crear el otro dir.
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el pabellón principal");
SetIntLong("Estás en el pabellón principal de este nivel, no hay lámparas, pero "
"se ve "
"con la luz de las lámparas anteriores y las que hay mas adelante.\n"
"El tubo continúa por el techo.\n");

SetIntBright(40);
AddExit("este", MPISO1+"septima");
AddExit("oeste", MPISO1+"quinta");
AddExit("abajo", MPISO2+"primera2");
AddDetail(({"tubo","especie de tubo"}),
"Es una especie de tubo de ventilacion para que el aire fresco circule por \
toda "
"la mina.\n");

SetIntSmell(
"Hueles a tierra y a metal.\n");
SetIntNoise(
"Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n");
}