
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un dormitorio");
    SetIntLong(
    "La estancia es un enorme dormitorio con una cama grande que se halla "
    "en medio. Tanto las cortinas como la tapicería de cada uno de los muebles de "
    "un color morado y tienen bordado el escudo de armas del castillo.\n Hay "
    "una gran puerta de roble en la pared este del dormitorio.\n");
    SetIntSmell("La habitacion huele a limpio.\n");
    SetIntBright(45);
    AddExit("este", "./pasillo8");
    AddDoor("este", "una gran puerta",
    "Es una gran puerta de roble para salir al pasillo.\n",
    ({"puerta", "puerta de roble", "gran puerta", "gran puerta de roble", "puerta del este"}));
    SetLocate("el castillo de Nandor");
}
