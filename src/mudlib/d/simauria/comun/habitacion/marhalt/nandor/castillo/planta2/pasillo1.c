
#include <properties.h>

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un pasillo interior");
    SetIntLong(
    "El pasillo está perfectamente limpio, del techo cuelga un gran tapiz con "
    "el escudo de armas del castillo. Una gran escalera desciende hacia el nivel "
    "inferior y el pasillo se extiende al norte y al sur.\n");
    SetIntBright(45);
    SetIntNoise("El sonido de la planta inferior llena esta habitacion.\n");
    AddDetail(({"escaleras", "escalera"}),
    "Una amplia escalera de piedra que desciende en semicírculo a "
    "la planta inferior. Los anchos pasamanos y las columnatas finales con la parte "
    "superior tallada en forma de yelmo cilíndrico están hechas en mármol blanco, muy "
    "raro en esta zona del reino.\n");

    AddDetail("tapiz",
    "Representa una flor de lis dorada y un mandoble sobre fondo marrón verdoso.\n");
    AddExit("norte", "./pasillo8");
    AddExit("oeste", "./hab10");
    AddExit("abajo", CASTILLO("planta1/pasillo6"));
    AddExit("sur", "./pasillo2");
    AddDoor("oeste", "una puerta de roble",
    "Es una puerta de roble de uno de los dormitorios.\n",
    ({"puerta", "puerta de roble", "puerta del oeste"}));
SetLocate("el castillo de Nandor");
}
