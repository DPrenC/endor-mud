
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un pasillo interior");
    SetIntLong(
    "El pasillo forma un recodo en este punto, en una de las esquinas hay un "
    "busto de una mujer, de facciones demasiado acentuadas, que parece vigilar "
    "lo que le rodea con su mirada.\n El pasillo sigue hacia el oeste y el sur.\n "
    "Una puerta al este da acceso a otra habitación del castillo, mientras que un "
    "lujoso arco da paso a otra estancia hacia el norte.\n");
    SetIntBright(45);
    AddExit("norte", "./hab08");
    AddExit("oeste", "./pasillo7");
    AddExit("este", "./hab07");
    AddExit("sur", "./pasillo5");
    AddDoor("este", "una puerta de madera",
    "Es una puerta de madera para entrar a una de las estancias.\n",
    ({"puerta", "puerta de madera", "puerta del este"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("sirvientes_castillo"), REFRESH_DESTRUCT);
}
