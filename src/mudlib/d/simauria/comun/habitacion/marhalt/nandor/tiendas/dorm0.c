
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un salón de descanso");
    SetIntLong("La gran habitación está llena de camastros para los viajantes, que no poseen "
           "mucho dinero para gastarlo en una habitación individual.\n las paredes están llenas de "
           "restos de musgo debido a la gran humedad de la sala, ciertamente no debe ser "
           "un lugar seguro para descansar, aunque algo mejor que la calle.\n");
    SetIntBright(35);
    SetIntSmell("El olor a sudor y cansancio casi se puede palpar.");
    AddItem(NPC_AZMODAN("bormius"),REFRESH_DESTRUCT);
    AddExit("norte","./pasi0");
    AddDoor("norte", "la puerta del pasillo",
    "Una vieja puerta de madera que da salida al pasillo de la posada.\n",
    ({"puerta", "puerta del pasillo", "puerta del norte"}));
}