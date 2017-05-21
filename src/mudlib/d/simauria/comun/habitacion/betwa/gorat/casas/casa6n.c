
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("una casa de Gorat");
SetIntLong(
    "est�s en una casa de pescadores, como tantas otras de este pueblo.\n "
    "la casa es blanca y peque�a, con un tejado de tejas rojas perfectamente alineadas.\n");
    SetIntBright(30);

    AddExit("sur","../calles/callep7");
    AddDoor("sur", "la puerta de la calle", "Una puerta normal de madera.\n",
    ({"puerta", "puerta de madera", "puerta del norte"}));
    AddItem(GORPNJ("ciudada2"), REFRESH_DESTRUCT,1);
    AddItem(GORPNJ("mujer"), REFRESH_DESTRUCT,2);
}
