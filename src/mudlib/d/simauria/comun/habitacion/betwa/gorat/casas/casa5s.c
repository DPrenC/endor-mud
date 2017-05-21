
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("una casa de Gorat");
    SetIntLong(
    "estás en una casa de pescadores, como tantas otras de este pueblo.\n "
    "La casa está notablemente sucia, contrastando con el resto de casas de Gorat que "
    "suele ser de gente bastante curiosa.\n");
    SetIntBright(30);

    AddExit("norte","../calles/callep5");
    AddDoor("norte", "la puerta de la calle");
    AddItem(GORPNJ("ciudadan"), REFRESH_DESTRUCT,2);
}
