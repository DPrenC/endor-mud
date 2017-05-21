/*
Por [F] Fran@simauria
        25 Jul, 1998: Pasillo primer nivel
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el pabellón principal");
SetIntLong("Estás en el pabellón principal, hay unas lámparas que producen un"
 "poco "
"de luz.El tubo continúa por el techo.\n"
"El túnel se bifurca hacia el nordeste y sudeste.\n");
SetIntBright(60);
AddExit("oeste",MPISO1+"sexta");
AddExit("nordeste",MPISO1+"bifne1");
AddExit("sudeste",MPISO1+"bifso1");
AddDetail(({"tubo","especie de tubo"}),
"Es una especie de tubo de ventilacion para que el aire fresco circule por \
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
"Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n");
}