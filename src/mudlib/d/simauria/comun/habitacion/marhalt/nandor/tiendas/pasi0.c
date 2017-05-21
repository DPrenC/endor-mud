
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("el pasillo de los dormitorios");
    SetIntLong("El final de la escalera termina en un peque�o pasillo, cuyo �nico "
    "adorno es un peque�o cuadro.\n Las paredes, como el resto del edificio, est�n "
    "hechas de madera.\n El pasillo sigue hacia el oeste y hay una puerta en el "
    "lado sur del pasillo, que lleva a una gran habitaci�n.\n");
    SetIntBright(25);
    AddExit("oeste","./pasi1");
    AddExit("sur","./dorm0");
    AddExit("abajo","./posada");
    AddDetail("cuadro","El cuadro representa a una criatura, un ghoul, en un cementerio.\n");
    AddDoor("sur", "una puerta",
    "Es una puerta para entrar a una de las habitaciones de la posada.\n",
    ({"puerta", "puerta de la habitaci�n", "puerta de la habitacion", "puerta del sur"}));
}
