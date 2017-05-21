/*
Por [F] Fran@simauria
        7 Nob, 1998: Pasillo Subnivel 2
	15 oct 1999: adicion bifurcacion sur
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el subnivel 2");

SetIntLong("Est�s en el subnivel 2, hay l�mparas en las paredes que iluminan el t�nel.\n"
"El tubo contin�a por el techo.\n");
SetIntBright(60);
AddExit("este",MPISO2+"sexta2");
AddExit("oeste",MPISO2+"cuarta2");
AddExit("sur",MPISO2+"bifsur2");
AddDetail(({"tubo"}),
"Es un tubo de ventilacion para que el aire fresco circule por \
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
"Oyes golpes de pico a lo lejos.\n");
}