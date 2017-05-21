
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un pasillo interior");
    SetIntLong(
    "Un gran retrato de un hombre vestido con ricas ropas, y con el blason del "
    "castillo domina la pared oeste del pasillo, que sigue hacia el norte y el "
    "sur.\n En el este del pasillo hay otra puerta de otra habitacion.\n");
    SetIntBright(45);
    AddExit("norte", "./pasillo6");
    AddExit("este", "./hab06");
    AddExit("sur", "./pasillo4");
    AddDoor("este", "una puerta de madera",
    "Es una puerta de madera para entrar a una de las estancias de esta planta.\n",
    ({"puerta", "puerta de madera", "puerta del este"}));
    SetLocate("el castillo de Nandor");
}
