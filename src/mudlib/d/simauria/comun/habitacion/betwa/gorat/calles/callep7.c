
#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetLocate("gorat");
    SetIntShort("la calle principal de Gorat");
    SetIntLong("Estás al final de la calle principal del pequeño y tranquilo pueblo de "
    "Gorat. Tanto al norte como al sur te encuentras con ambas típicas casas de "
    "la región, mientras que al oeste puedes llegar al puerto o salir del pueblo si lo "
    "deseas.\n");
    SetIndoors(0);
    AddExit("norte", "../casas/casa6n");
    AddExit("sur", "../casas/casa6s");
    AddExit("oeste", "./callep6");
    AddDoor("norte", "la puerta de una casa", "Una puerta normal de madera.\n",
    ({"puerta", "puerta de madera", "puerta del norte"}));
    AddDoor("sur", "la puerta de una casa", "Una puerta normal de madera.\n",
    ({"puerta", "puerta de madera", "puerta del sur"}));
}
