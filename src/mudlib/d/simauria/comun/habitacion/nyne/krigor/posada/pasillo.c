
#include "./path.h"


inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("el pasillo de los dormitorios");
    SetIntLong("Est�s en un peque�o pasillo en la posada de Krigor.\n Al sur se "
    "entra a una habitaci�n donde se hospedan los viajeros que tienen poco dinero y "
    "al oeste se entra a una habitaci�n algo m�s lujosa.\n");
    SetIntBright(45);
    AddExit("oeste",KRIGOR("posada/dormitorio01"));
    AddExit("sur",KRIGOR("posada/dormitorio02"));
    AddExit("abajo",KRIGOR("posada/posada"));
    AddDoor("sur", "la puerta de la habitaci�n humilde",
    "Esa puerta es para entrar a la habitaci�n humilde.\n",
    ({"puerta", "puerta del sur", "puerta de la habitaci�n humilde"}));
    AddDoor("oeste", "la puerta de la habitaci�n lujosa",
    "Es la puerta para entrar en la habitaci�n lujosa",
    ({"puerta", "puerta del oeste", "puerta de la habitaci�n lujosa"}));
}
