
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("una casa de Gorat");
SetIntLong(
    "estás en el interior de una casa de pescadores, como tantas otras de este pueblo. "
    "la casa es blanca y pequeña, pero parece cómoda.\n");
    SetIntBright(30);

    AddExit("norte","../calles/callep4");
    AddDoor("norte", "la puerta de la calle", "Una puerta normal de madera.\n",
    ({"puerta", "puerta de madera", "puerta del sur"}));
    AddItem(GORPNJ("mujer"), REFRESH_DESTRUCT,d2());
    }
