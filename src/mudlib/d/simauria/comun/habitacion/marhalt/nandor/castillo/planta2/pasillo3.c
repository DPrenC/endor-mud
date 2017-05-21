
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un pasillo interior");
    SetIntLong(
    "Las paredes están decoradas con tapices que describen batallas de epocas "
    "pasadas.\n El pasillo continua hacia el oeste y el este. En la pared sur del "
    "pasillo hay una puerta hacia una nueva habitacion.\n");
    SetIntBright(45);
    AddExit("oeste", "./pasillo2");
    AddExit("este", "./pasillo4");
    AddExit("sur", "./hab03");
    AddDoor("sur", "una puerta de madera",
    "Una puerta de madera que da entrada a una de las habitaciones del castillo.\n",
    ({"puerta", "puerta de madera", "puerta de la habitación", "puerta del sur"}));
    SetLocate("el castillo de Nandor");
}