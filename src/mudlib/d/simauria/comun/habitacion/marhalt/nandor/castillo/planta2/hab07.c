
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("la sala de reuniones");
    SetIntLong(
    "La sala es bastante ámplia y los muebles son mas bien escasos: una gran mesa "
    "y sillas, para sentarse en ella, son los unicos muebles de la habitación. unos "
    "cuantos candelabros descansan sobre la mesa, que parece un poco vieja y usada. "
    "Una puerta de madera da salida al pasillo por el oeste.\n");
    SetIntBright(45);
    AddExit("oeste", "./pasillo6");
    AddDoor("oeste", "una puerta de madera",
    "Una puerta de madera para volver al pasillo.\n",
    ({"puerta", "puerta de madera", "puerta del pasillo", "puerta del oeste"}));
    SetLocate("el castillo de Nandor");
}
