
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("la calle principal de Gorat");
    SetIntLong("Estás en el centro de la calle principal de Gorat, tanto al norte como "
    "al sur tienes distintas casas pequeñas típicas del pueblo.\n La calle continúa "
    "hacia el puerto en dirección oeste y hacia el final de la calle en dirección este.\n");
    SetIndoors(0);
    AddExit("este","./callep5");
    AddExit("norte","../casas/casa2n");
    AddExit("sur","../casas/casa2s");
    AddExit("oeste","./callep3");
    AddDoor("norte", "la puerta de una casa", "Una puerta normal de madera.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
    AddDoor("sur", "la puerta de una casa", "Una puerta normal de madera.\n",
    ({"puerta", "puerta de madera", "puerta del sur"}));
    AddItem(GORPNJ("guard2"), REFRESH_DESTRUCT, 1);
    AddItem(GORPNJ("guard"), REFRESH_DESTRUCT,1);
}
