
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un pasillo interior");
    SetIntLong(
    "Un gran jarrón de cerámica pintado en colores, que desentonan con la decoración "
    "del resto del castillo, reposa sobre un pedestal de madera colocado en la pared "
    "sur del pasillo.\n El pasillo continúa hacia el oeste y el este. Al norte hay "
    "una puerta doble.\n");
    SetIntBright(45);
    AddDetail(({"jarrón", "jarron"}),
    "¿ómo describirlo?, Es un amasijo de colores pistacho y fucsia representando "
     "escenas grotescas.\n");
    AddExit("oeste", "./pasillo8");
    AddExit("este", "./pasillo6");
    AddExit("norte", "./hab09");
    AddDoor("norte", "la puerta de un dormitorio",
    "Es la puerta para entrar a uno de los dormitorios de esta planta.\n",
    ({"puerta", "puerta de madera", "puerta del dormitorio", "puerta del norte"}));
    SetLocate("el castillo de Nandor");
}
