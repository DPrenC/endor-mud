
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("una casa de Gorat");
    SetIntLong(
    "estás en una casa de pescadores, como tantas otras de este pueblo, "
    "la casa es blanca, con un tejado de tejas rojas perfectamente alineadas.\n");
    SetIntBright(30);

    AddExit("sur","../calles/callep4");
    AddDoor("sur", "la puerta de la calle", "Una puerta normal de madera.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
    AddItem(GORPNJ("ciudadan"), REFRESH_DESTRUCT, 1);
    AddItem(GORPNJ("mujer"), REFRESH_DESTRUCT,1);

}
