
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("una habitación");
    SetIntLong("La habitación tiene dos camastros y está bastante limpia.\n"
    " Una ventana permite que entre algo de luz del esterior.\n  Los camastros y las "
    "mantas son lo bastante acogedoras como para descansar un poco, tras un largo "
    "viaje sin temor a las pulgas.\n Una silla de madera cumple la función de perchero "
    "y armario.\n");
    SetIntBright(35);
    AddExit("sur","./pasi1");
    AddDoor("sur", "la puerta del pasillo",
    "Una puerta vieja para salir al pasillo.\n",
    ({"puerta", "puerta del pasillo", "puerta vieja", "puerta del sur"}));
}