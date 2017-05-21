
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("el pasillo de los dormitorios");
    SetIntLong("Est�s en el �ltimo tramo del pasillo, la madera esta gastada por el "
    "paso del tiempo. Se ven algunos ara�azos provocados, posiblemente, por alguien "
    "durante una pelea.\n Hay una habitaci�n al oeste y otra al norte.\n");
    SetIntBright(25);
    AddExit("oeste","./dorm3");
    AddExit("norte","./dorm2");
    AddExit("este","./pasi1");
    AddDoor("oeste", "una puerta",
    "Es una puerta para entrar a una de las habitaciones de la posada.\n",
    ({"puerta", "puerta de la habitaci�n", "puerta de la habitacion", "puerta del oeste"}));
    AddDoor("norte", "una puerta",
    "Es una puerta para entrar a una de las habitaciones de la posada.\n",
    ({"puerta", "puerta de la habitaci�n", "puerta de la habitacion", "puerta del norte"}));

}