
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

  SetIntShort("una habitación individual");
    SetIntLong("La habitación tiene una única cama que está bastante limpia, al "
    "igual que el resto de la estancia\n Parece que se ha dejado un espacio para "
    "un posible segundo ocupante.\n Hay un armario y una silla.\n");
    SetIntBright(35);
    AddExit("sur","./pasi2");
    AddDoor("sur", "la puerta del pasillo",
    "La puerta para salir de la habitación.\n",
    ({"puerta", "puerta del pasillo", "puerta del sur"}));
}