/*
Por [F] Fran@simauria
        25 Feb, 1998: El principio de las minas... normal...
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("la entrada a las minas");
SetIntLong("Estas en la entrada a las minas, hay unas l�mparas que producen un"
 "poco "
"de luz.Tambien hay una especie de tubo en el techo.\n"
"El t�nel sigue hacia adelante.\n");

SetIntBright(60);
AddExit("este",MPISO1+"segunda");
AddExit("oeste", "/players/fran/workroom");
AddDetail(({"tubo","especie de tubo"}),
"Es una especie de tubo de ventilacion para que el aire fresco circule por \
toda "
"la mina.\n");
AddDetail(({"l�mpara","l�mparas"}),
"En cada pared hay una l�mpara de aceite que da iluminacion.Tienen "
" un simbolo junto al gancho que las fija a la pared.\n");

AddDetail(({"simbolo"}),
"Es una forja con una inscripcion: 'Metalurgias Ivos'.\n");
AddDetail(({"placa","letrero"}),
"Es una placa de metal. Tiene algo escrito.\n");
AddReadMsg(({"placa","letrero"}),
"\n\El cartel pone: "
" "
"    ______________________ "
"   |     Minas de Ivos    | "
"   | Mayor cantera minera | "
"   |         del          | "
"   |        Reino         | "
"   |______________________| "
"\n");
SetIntSmell(
"Hueles a tierra y a metal.\n");
SetIntNoise(
"Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n");
}
