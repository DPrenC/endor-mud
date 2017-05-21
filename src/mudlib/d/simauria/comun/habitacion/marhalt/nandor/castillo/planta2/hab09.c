
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un dormitorio doble");
    SetIntLong(
    "El dormitorio está bien cuidado, dos camas bien hechas dominan el centro de "
    "la habitación.\n Hay una mesita de noche, con sus candelabros, a cada lado de las "
    "camas.\n Un armario cerrado descansa en la pared este.\n");
    SetIntBright(35);
    AddExit("sur", "./pasillo7");
    AddDoor("sur", "la puerta del pasillo",
    "Es una puerta de madera para salir al pasillo.\n",
    ({"puerta", "puerta de madera", "puerta del pasillo", "puerta del sur"}));
    SetLocate("el castillo de Nandor");
}
