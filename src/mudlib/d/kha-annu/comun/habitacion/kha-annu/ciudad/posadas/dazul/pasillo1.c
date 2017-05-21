#include "path.h"
#include <moving.h>
#include <properties.h>
#include <materials.h>
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("la posada del Dragón Azul");
    SetIntLong("Aquí es donde están las habitaciones. Hay una justo enfrente y dos mas a cada "
        "lado del pasillo. Detrás quedan las escalerass que llevan al primer piso.\n");
    SetIntBright(70);
    SetIndoors(1);
    SetLocate("ciudad de Kha-annu");
    AddDetail(({"habitaciones"}),"Hay tres habitaciones. Te fijas de pasada en cada una de "
        "ellas.\n");
    AddDetail(({"alfombra","gran alfombra"}),"La alfombra cubre el pasillo y seguramente las "
        "habitaciones.\n");
    AddDetail(({"escalera","escaleras"}),"Las escaleras quedan justo detrás del pasillo.\n"
        "Llevan al primer piso.\n");
    AddExit("norte","habita1");
    AddExit("oeste","habita2");
    AddExit("este","habita3");
    AddExit("escaleras","posada1");
    AddDoor("norte","la puerta de la habitación simple",
        "Es una simple puerta de madera, como las que pudieras encontrar en "
        "cualquier casa.\n",
        ({"puerta","puerta norte","puerta simple","puerta de habitacion simple"}),GENDER_FEMALE,"llave1_s",
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
    AddDoor("oeste","la puerta de la habitación normal",
        "Es una simple puerta de madera, como las que pudieras encontrar en "
            "cualquier casa.\n",
        ({"puerta","puerta oeste","puerta normal","puerta de habitacion normal"}),GENDER_FEMALE,"llave2_n",
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
    AddDoor("este","la puerta de la habitación lujosa",
        "Es una simple puerta de madera, como las que pudieras encontrar en "
            "cualquier casa.\n",
        ({"puerta","puerta este","puerta lujosa","puerta de habitacion lujosa"}),GENDER_FEMALE,"llave3_l",
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
}
