/*
Por [F] Fran@simauria
        7 Nob, 1998: peaso de minas subnivel 2. Pasillo medio
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("un túnel en el subnivel 2");
SetIntLong("Estas en un túnel en el subnivel 2, las lámparas iluminan esta parte "
"con su luz.El tubo continúa por el techo.Hay una placa en la pared.\n");

SetIntBright(70);
AddExit("este",MPISO2+"cuarta2");
AddExit("oeste",MPISO2+"segunda2");
AddDetail(({"tubo","especie de tubo"}),
"Es el tubo de ventilacion para que el aire fresco circule por toda "
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