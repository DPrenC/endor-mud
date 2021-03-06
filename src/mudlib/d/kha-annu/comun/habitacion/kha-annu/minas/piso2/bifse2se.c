/*
Por [F] Fran@simauria
       17 nov 1999
*/
#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el Subnivel 2");
  SetIntLong(
    "Est�s en el subnivel 2, hay l�mparas en las paredes que iluminan el t�nel.\n"
    "El tubo contin�a por el techo.Hay una placa en la pared.\n"
    );
  SetIndoors(1);
  SetIntBright(60);
  SetIntSmell(
    "Hueles a tierra y a metal.\n"
    );
  SetIntNoise(
    "Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n"
    );
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
  AddExit("noreste",MPISO2+"bifne2se4");
  AddExit("suroeste",MPISO2+"bifse2se1");
  SetLocate("");
}