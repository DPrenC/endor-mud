
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un dormitorio");
    SetIntLong(
    "El dormitorio est� dominado por una cama de madera noble situada en el centro "
    "de la habitaci�n. Tanto las cortinas como la tapicer�a de cada uno de los "
    "muebles est�n hechas por verdaderos artesanos, a juzgar por su perfecto "
    "acabado. Puedes ver una gran puerta de roble en la pared oeste del dormitorio.\n");
    SetIntBright(45);
    AddExit("oeste", "./pasillo4");
    AddDoor("oeste", "una puerta de roble",
    "Una puerta de roble para volver al pasillo.\n",
    ({"puerta", "puerta de madera", "puerta del pasillo", "puerta del oeste",
        "puerta de roble"}));
    SetLocate("el castillo de Nandor");
}
