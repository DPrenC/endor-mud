#include <mud.h>
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
Set(P_INT_SHORT,"un sendero");
SetIntLong(
"Has dejado el bosque hacia atras y te has internado en la zona agricola. "
"Sigues un camino que se encuentra rodeado de campos de cultivo.\n");

SetIndoors(0);
SetIntNoise("Solo oyes el ruido del viento.\n");
SetIntSmell("Fragancias campestres inundan tus sentidos.\n");
SetLocate("Nandor");

AddDetail(({"campos de cultivo","campo","campos","cultivo","cultivos"}),
"Son grandes extensiones de tierra cultivada que dan fama a esta zona.\n");
AddExit("oeste","./sendero8");
AddExit("este","./cruce");
}
