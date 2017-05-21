/*
Por [F] Fran@simauria
        7 Nob, 1998: segundo subnivel.
*/

#include "path.h"
inherit KHA_ROOM;
create() {
::create();

SetIntShort("el principio del segundo nivel");
SetIntLong("Estas en la entrada al segundo subnivel, ves el tipo de lámparas que estan "
"por toda la mina.El tubo de ventilacion entra del techo y continúa hacia "
"el fondo del túnel y hacia abajo por el suelo. Hay una placa sucia en la pared.\n");

SetIntBright(60);
AddExit("arriba", MPISO1+"sexta");
AddExit("este",MPISO2+"segunda2");
AddDetail(({"tubo","tubo de ventilacion"}),
"Es el tubo de la ventilacion... si no estubiera seria un problema.\n");
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
SetIntSmell(
"Hueles a tierra y a metal.\n");
SetIntNoise(
"Oyes golpes de pico y a algunos enanos con sus gritos.\n");
}