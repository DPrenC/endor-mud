
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un pasillo interior");
    SetIntLong(
    "El pasillo forma un recodo, en una de las esquinas hay una estatua de mármol "
    "blanco que representa a un caballero lanza en ristre.\n El pasillo sigue hacia "
    "el este y el norte. Dos puertas situadas al oeste y al sur dan acceso a otras "
    "estancias del castillo.\n");
    SetIntBright(45);
    AddExit("norte", "./pasillo1");
    AddExit("oeste", "./hab01");
    AddExit("este", "./pasillo3");
    AddExit("sur", "./hab02");
    AddDoor("sur", "una puerta dorada",
    "Es una puerta de madera, aunque tiene algún tratamiento especial, pues su color "
    "dorado no debe de ser natural.\n",
    ({"puerta", "puerta de madera", "puerta dorada", "puerta del sur"}));
    AddDoor("oeste", "una puerta de madera",
    "Una puerta de madera para entrar a una de las estancias del castillo.\n",
    ({"puerta", "puerta de madera", "puerta del oeste"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("sirvientes_castillo"), REFRESH_DESTRUCT);
}
