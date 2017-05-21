#include <mud.h>
#include <properties.h>
#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();
Set(P_INT_SHORT,"el piso superior");
SetIntLong(
"Te encuentras al final de las escaleras  que acceden al piso de arriba.\n"
"Solo hay una habitacion que ocupa todo el espacio. Tiene varias camas\n"
"y cuatro pequenyas ventanas, una en cada direccion.\n");

SetIndoors(1);
SetIntBright(30);

SetIntNoise("");
SetIntSmell("Huele a humanidad. Parece que no entre aire limpio aqui.");
SetLocate("nandor");

AddDetail(({"cama","camas"}),
"Son simples camastros sin hacer.");
AddDetail(({"ventana","ventanas"}),
"Pequenyas aberturas acristaladas que hay en la pared. Senyalan en todas direcciones.\n");
AddExit("abajo","granja1");
}

