/*
Por [F] Fran@simauria
       17 nov 1999
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el subnivel 2");
SetIntLong("Estás en el subnivel 2, hay lámparas en las paredes que iluminan el túnel.\n"
"El tubo continúa por el techo.\n");

SetIntBright(40);
AddExit("sudeste",MPISO2+"bifne2se");
AddExit("suroeste",MPISO2+"septima2");
AddExit("nordeste",MPISO2+"bifne22");
AddDetail(({"tubo","especie de tubo"}),
"Es una especie de tubo de ventilacion para que el aire fresco circule por \
toda "
"la mina.Hay una placa abollada en la pared.\n");

AddDetail(({"lámpara","lámparas"}),
"En cada pared hay una lámpara de aceite que da iluminacion.Tienen "
" un simbolo junto al gancho que las fija a la pared.\n");

AddDetail(({"simbolo"}),
"Es una forja con una inscripcion: 'Metalurgias Ivos'.\n");
  AddDetail(({"placa","letrero"}),
"Es una placa de metal un poco abollada y sucia. Tiene algo escrito.\n");
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

SetIntSmell("Hueles a tierra y a metal.\n");
SetIntNoise("Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n");
}