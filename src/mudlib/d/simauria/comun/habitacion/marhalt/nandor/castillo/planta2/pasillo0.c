

#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un pasillo interior");
    SetIntLong(
    "Esta pequeña prolongación del pasillo está construido de robusta piedra color "
    "negro.\n Un gran hacha y una maza, de enormes dimensiones, están colgados de "
    "la pared oeste.\n Hacia el norte hay una salida a la muralla del castillo, mientras"
    " que  un gran arco de piedra, en la parte este de la sala, domina la entrada "
    "al pasillo interior de esta planta de la torre principal del castillo.\n");
    SetIntBright(45);
    SetIntNoise(
"   El sonido de los cantos de los pajaros del exterior llega a esta sala.\n");
    AddExit("norte", CASTILLO("murallas/muralla01"));
    AddExit("sur", "./pasillo8");
    SetLocate("el castillo de Nandor");
}
