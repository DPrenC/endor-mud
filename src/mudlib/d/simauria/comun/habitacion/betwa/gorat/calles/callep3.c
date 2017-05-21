
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("la calle principal de Gorat");
    SetIntLong("Estás en la calle principal del pequeño pueblo pesquero de Gorat.\n "
    "Hacia el oeste llegas al puerto, mientras que al este te adentras un poco más "
    "en el pueblo.\n");
    SetIndoors(0);
    AddExit("este","./callep4");
    AddExit("oeste","./callep2");
    AddExit("norte", "../casas/casa3n");
    AddExit("sur", "../casas/casa3s");
    AddDoor("norte", "la puerta de una casa");
    AddDoor("sur", "la puerta de una casa");
    AddItem(GORPNJ("guard2"),REFRESH_DESTRUCT,1 );
    AddItem(GORPNJ("ciudada2"), REFRESH_DESTRUCT,1);
    AddItem(GORPNJ("ciudadan"), REFRESH_DESTRUCT,1);
}
