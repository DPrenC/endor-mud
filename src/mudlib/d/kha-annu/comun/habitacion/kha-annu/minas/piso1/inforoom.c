/*
Por [F] Fran@simauria
        25 Feb, 1998: Las minas. habitacion de información nivel 1.
*/
#include "./path.h"
inherit KHA_ROOM;
create() {
::create();

SetIntShort("el cuarto de información");
SetIntLong("Estás en el cuarto de información de los niveles, hay lámparas en las "
 "paredes, "
"una mesa, una silla y un tablon en la pared.\n");

SetIntBright(70);
AddExit("norte", MPISO1+"segunda");

AddDetail(({"lámpara","lámparas"}),
"En cada pared hay una lámpara de aceite que da iluminacion.Tienen "
" un simbolo junto al gancho que las fija a la pared.\n");

AddDetail(({"simbolo"}),
"Es una forja con una inscripcion: 'Metalurgias Ivos.'.\n");

SetIntSmell(
"Hueles a tierra y a metal.\n");
SetIntNoise(
"Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n");
}