
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("el pasillo de los dormitorios");
    SetIntLong("La madera de esta parte del pasillo está un poco desgastada por el "
    "efecto del paso del tiempo.\n Del techo cuelga una gran lámpara que, aunque no muy "
    "elaborada, cumple su función.\n El pasillo sigue hacia el oeste, hay una puerta al "
    "lado norte del pasillo.\n");

    SetIntBright(25);

    AddExit("este","./pasi0");
    AddExit("oeste","./pasi2");
    AddExit("norte","./dorm1");
    AddDoor("norte", "una puerta",
    "Es una puerta para entrar a una de las habitaciones de la posada.\n",
    ({"puerta", "puerta de la habitación", "puerta de la habitacion", "puerta del norte"}));
}
