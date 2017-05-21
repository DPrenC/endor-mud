
#include "./path.h"


inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("el pasillo de los dormitorios");
    SetIntLong("Estás en un pequeño pasillo en la posada de Krigor.\n Al sur se "
    "entra a una habitación donde se hospedan los viajeros que tienen poco dinero y "
    "al oeste se entra a una habitación algo más lujosa.\n");
    SetIntBright(45);
    AddExit("oeste",KRIGOR("posada/dormitorio01"));
    AddExit("sur",KRIGOR("posada/dormitorio02"));
    AddExit("abajo",KRIGOR("posada/posada"));
    AddDoor("sur", "la puerta de la habitación humilde",
    "Esa puerta es para entrar a la habitación humilde.\n",
    ({"puerta", "puerta del sur", "puerta de la habitación humilde"}));
    AddDoor("oeste", "la puerta de la habitación lujosa",
    "Es la puerta para entrar en la habitación lujosa",
    ({"puerta", "puerta del oeste", "puerta de la habitación lujosa"}));
}
