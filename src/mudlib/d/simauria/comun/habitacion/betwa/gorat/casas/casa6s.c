
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("una casa de Gorat");
    SetIntLong("Esta es una de las tantas casas típicas de la región de Betwa, que "
    "suelen ser blancas y pequeñas.\n La casa presenta un aspecto algo desaliñado, "
    "pero aún así se puede vivir bien.\n");
    SetIntBright(30);

    AddExit("norte","../calles/callep7");
    AddDoor("norte", "la puerta de la calle", "Una puerta normal de madera.\n",
    ({"puerta", "puerta de madera", "puerta del sur"}));
    AddItem(GORPNJ("mujer"), REFRESH_DESTRUCT,1);
}
