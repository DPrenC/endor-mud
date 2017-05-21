
#include "./path.h"
#include <door.h>
#include <nightday.h>

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("la calle principal de Gorat");
    SetIntLong("Estás en la calle principal del pueblo pesquero de Gorat, tanto al "
    "este como al oeste continúa la calle, y al norte tienes la tasca del pueblo.\n");
    SetIndoors(0);
    AddExit("este","./callep6");
    AddExit("oeste","./callep4");
    AddExit("norte","../tiendas/tasca");
    AddExit("sur", "../casas/casa5s");
    AddDoor("norte", "la puerta de la tasca",
    "Es una puerta de madera que da entrada a la tasca del pueblo de Gorat.\n",
    ({"puerta", "puerta de madera", "puerta de la tasca", "puerta del norte"}),
    ([P_DOOR_CLOSE_TIME : ({ND_NIGHT, ND_PREDAWN, ND_DAWN})]));
    AddDoor("sur", "la puerta de una casa");
    AddItem(GORPNJ("guard"), REFRESH_DESTRUCT, 1);
    AddItem(GORPNJ("ciudada2"), REFRESH_DESTRUCT, 1);
}
