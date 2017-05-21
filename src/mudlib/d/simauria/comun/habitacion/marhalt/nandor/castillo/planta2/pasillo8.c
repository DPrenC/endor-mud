

#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un pasillo interior");
    SetIntLong(
    "El pasillo forma un recodo en este punto, en una de las esquinas hay un arpa "
    "de cristal sobre un pedestal de mármol. El pasillo continua en direccion sur "
    "y este.\n  Una puerta situada al oeste da acceso a una nueva habitación del "
    "castillo, mientras que un arco de piedra en la parte norte da paso a una "
    "prolongación del pasillo.\n");
    SetIntBright(45);
    AddDetail(({"arpa", "arpa de cristal"}),
    "Es un arpa de cristal tallado, bellamente trabajada, quizá por elfos. Refleja "
    "la luz formando un bello efecto de caleidoscopio.\n");
    AddExit("norte","./pasillo0");
    AddExit("oeste", "./hab11");
    AddExit("este", "./pasillo7");
    AddExit("sur", "./pasillo1");
    AddDoor("oeste", "una gran puerta",
    "Es una gran puerta de roble que da entrada a uno de los dormitorios.\n",
    ({"puerta", "puerta de roble", "gran puerta", "gran puerta de roble", "puerta del oeste"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("sirvientes_castillo"), REFRESH_DESTRUCT);
}
