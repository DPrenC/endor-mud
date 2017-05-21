
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

  SetIntShort("una habitaci�n individual");
    SetIntLong("La habitaci�n tiene una �nica cama que est� bastante limpia, al "
    "igual que el resto de la estancia\n Parece que se ha dejado un espacio para "
    "un posible segundo ocupante.\n Hay un armario y una silla.\n");
    SetIntBright(35);
    AddExit("sur","./pasi2");
    AddDoor("sur", "la puerta del pasillo",
    "La puerta para salir de la habitaci�n.\n",
    ({"puerta", "puerta del pasillo", "puerta del sur"}));
}