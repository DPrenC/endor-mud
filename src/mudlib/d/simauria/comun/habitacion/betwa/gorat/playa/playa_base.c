/****************************************************************************
Fichero: playa_base.c
Autor: Ratwor
Fecha: 17/11/2007
Descripción: La playa de Gorat
****************************************************************************/

#include "./path.h"
#include <sounds.h>
inherit SIM_ROOM;

create(){
    ::create();
    SetLocate("puerto de Gorat");
    SetIntShort("una playa de rocas");
    SetIndoors(0);
    SetIntNoise("Se escucha el agradable sonido de las olas rompiendo contra las rocas.\n");
    SetIntSmell("Huele a mar.\n");
    AddDetail(({"mar", "agua"}), "Contemplas la inmensidad del mar.\n");
    AddDetail(({"rocas", "roca", "piedras", "piedra"}), "La playa está formada por "
    "montones de rocas sueltas.\n");
    AddDetail("faro", "Se levanta majestuoso en medio de la playa.\n");

    SetSoundEnvironment(SND_AMBIENTES("olas"), 30);
}
