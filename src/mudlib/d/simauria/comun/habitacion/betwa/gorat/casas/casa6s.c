
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("una casa de Gorat");
    SetIntLong("Esta es una de las tantas casas t�picas de la regi�n de Betwa, que "
    "suelen ser blancas y peque�as.\n La casa presenta un aspecto algo desali�ado, "
    "pero a�n as� se puede vivir bien.\n");
    SetIntBright(30);

    AddExit("norte","../calles/callep7");
    AddDoor("norte", "la puerta de la calle", "Una puerta normal de madera.\n",
    ({"puerta", "puerta de madera", "puerta del sur"}));
    AddItem(GORPNJ("mujer"), REFRESH_DESTRUCT,1);
}
