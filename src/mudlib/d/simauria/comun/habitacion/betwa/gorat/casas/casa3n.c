
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("una casa de Gorat");
    SetIntLong(
    "estás en una casa de pescadores, como tantas otras de este pueblo.\n "
    " La casa es pequeña, de pocas estancias, pero suficiente como para vivir un par "
    "de personas.\n");
    SetIntBright(30);

    AddExit("sur","../calles/callep3");
    AddDoor("sur", "la puerta de la calle");
    AddItem(GORPNJ("ciudadan"), REFRESH_DESTRUCT,2 );
}
