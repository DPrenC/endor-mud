
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

  SetIntShort("una habitaci�n");
  SetIntLong("La estancia est� ocupada por dos camas y dos camastros.\n "
           " La habitaci�n est� bastante limpia, lo cual la hace mas acogedora. Hay una lampara "
           "colgando del techo por una cuerda.\n");
    SetIntBright(35);
    AddExit("este","./pasi2");
    AddDoor("este", "la puerta del pasillo",
    "La puerta para salir al resto de la posada.\n",
    ({"puerta", "puerta del pasillo", "puerta del este"}));
}