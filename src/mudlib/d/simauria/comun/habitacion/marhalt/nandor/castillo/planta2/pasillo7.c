
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un pasillo interior");
    SetIntLong(
    "Un gran jarr�n de cer�mica pintado en colores, que desentonan con la decoraci�n "
    "del resto del castillo, reposa sobre un pedestal de madera colocado en la pared "
    "sur del pasillo.\n El pasillo contin�a hacia el oeste y el este. Al norte hay "
    "una puerta doble.\n");
    SetIntBright(45);
    AddDetail(({"jarr�n", "jarron"}),
    "��mo describirlo?, Es un amasijo de colores pistacho y fucsia representando "
     "escenas grotescas.\n");
    AddExit("oeste", "./pasillo8");
    AddExit("este", "./pasillo6");
    AddExit("norte", "./hab09");
    AddDoor("norte", "la puerta de un dormitorio",
    "Es la puerta para entrar a uno de los dormitorios de esta planta.\n",
    ({"puerta", "puerta de madera", "puerta del dormitorio", "puerta del norte"}));
    SetLocate("el castillo de Nandor");
}
