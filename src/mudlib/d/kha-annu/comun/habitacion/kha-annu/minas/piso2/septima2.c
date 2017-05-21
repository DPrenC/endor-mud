/*
Por [F] Fran@simauria
        15 oct 1999: Pasillo Subnivel 2
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el subnivel 2");
SetIntLong("Estás en el subnivel 2, hay lámparas en las paredes que iluminan el túnel.\n"
"El tubo continúa por el techo. Hay una placa en la pared.\n");

SetIntBright(60);
AddExit("oeste",MPISO2+"sexta2");
AddExit("nordeste",MPISO2+"bifne2");
AddDetail(({"tubo"}),
"Es un tubo de ventilacion para que el aire fresco circule por \
toda "
"la mina.\n");
AddDetail(({"lámpara","lámparas"}),
"En cada pared hay una lámpara de aceite que da iluminacion.Tienen "
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
"Oyes golpes de pico a lo lejos.\n");
}