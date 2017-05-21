/* Izet@Simauria */

#include "path.h"
inherit KHA_ROOM;
#include "stink.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("El corredor es más estrecho aquí. No ves nada interesante y solo percibes un "
        "desagradable olor. El sitio apesta, y solo puedes aguantar la respiración.\n");
    AddDetail(({"suelo"}),"Ves restos de comida por el suelo.\n");
    AddDetail(({"restos","restos de comida"}),"Resultan desagradables y te entran ganas de "
        "vomitar.\n");
    SetIntSmell("Puag!! Aqui apesta a muerte!\n");
    SetIntBright(30);
    SetIndoors(1);
    AddExit("norte",CLOACAS+"cloaca4");
/*
  AddExit("este",CLOACAS+"cloaca31");
*/
    AddExit("sur",CLOACAS+"cloaca2");
}
