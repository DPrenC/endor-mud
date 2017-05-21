/*
Por [F] Fran@simauria
        25 Jul, 1998: Pasillo primer nivel
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el fin del pabell�n");
SetIntLong("Est�s en el fin del pabell�n, hay unas l�mparas que producen un"
 "poco "
"de luz.El tubo acaba en el techo.\n"
"El t�nel se bifurca aqui.\n");
SetIntBright(60);
AddExit("noroeste",MPISO1+"bifne3");
AddExit("suroeste",MPISO1+"bifso3");
AddDetail(({"tubo","especie de tubo"}),
"Es una especie de tubo de ventilacion para que el aire fresco circule por \
toda "
"la mina.\n");
AddDetail(({"l�mpara","l�mparas"}),
"En la pared hay una l�mpara de aceite que da iluminacion.Tiene "
" un simbolo junto al gancho que la fija a la pared.\n");

AddDetail(({"simbolo"}),
"Es una forja con una inscripcion: 'Metalurgias Ivos'.\n");

  AddDetail(({"placa","letrero"}),
"Es una placa de metal un poco manchada. Tiene algo escrito.\n");
  AddReadMsg(({"placa","letrero"}),
"\n\El cartel pone: "
" "
"    ______________________ "
"   |********as de Ivos    | "
"   |****** cantera minera | "
"   |*****    del          | "
"   |****    Reino         | "
"   |______________________| "
"\n");
SetIntSmell(
"Hueles a tierra y a metal.\n");
SetIntNoise(
"No se oye nada por esta zona.\n");
}