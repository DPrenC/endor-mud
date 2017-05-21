
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un dormitorio");
    SetIntLong(
    "Una gran cama, de la madera mas noble, domina la habitación. sobre ella puedes "
    "ver un espejo con un marco de madera de muy bella factura. La habitacion está "
    "perfectamente limpia, prueba del buen trabajo de los sirvientes del castillo.\n "
    "Tienes una puerta de roble en la pared este del dormitorio.\n");
    SetIntSmell("Hmmm... huele a albaricoque.");
    SetIntBright(45);
    AddDetail("espejo",
    "Te ves reflejado en él.");
    AddExit("este", "./pasillo1");
        AddDoor("este", "una puerta de roble",
    "Es una puerta de roble para salir al pasillo de esta planta.\n",
    ({"puerta", "puerta de roble", "puerta del este"}));
    SetLocate("el castillo de Nandor");
}
