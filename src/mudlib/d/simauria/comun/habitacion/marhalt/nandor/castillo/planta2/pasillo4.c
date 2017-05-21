
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un pasillo interior");
    SetIntLong(
    "El pasillo forma un recodo en este punto, en una esquina hay una gran armadura "
    "que parece mirarte fijamente a través de su visera bajada.\n El pasillo sigue "
    "hacia el norte y el oeste. En las paredes este y sur hay dos puertas que dan "
    "acceso a nuevas estancias del castillo.\n");
    SetIntBright(45);
    AddExit("norte", "./pasillo5");
    AddExit("oeste", "./pasillo3");
    AddExit("este", "./hab05");
    AddExit("sur", "./hab04");
    AddDoor("sur", "una puerta celeste",
    "Es una puerta de madera, aunque tiene algún tratamiento especial, pues su color "
    "celeste no debe de ser natural.\n",
    ({"puerta", "puerta de madera", "puerta celeste", "puerta del sur"}));
    AddDoor("este", "una puerta de madera",
    "Una puerta de roble para entrar a una de las estancias.\n",
    ({"puerta", "puerta de madera", "puerta de roble", "puerta del este"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("sirvientes_castillo"), REFRESH_DESTRUCT);
}
