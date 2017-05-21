/*****************************************************************************
 AUTOR:		orome
 DETALLES:	posada abandonada
 *****************************************************************************/

#include "./path.h"

inherit ROOM;

create() {
    ::create();

    SetIntBright(20);
    SetLocate("una posada abandonada");
    SetIntShort("los dormitorios de la guardia");
    SetIntLong("Estás en los dormitorios de la guardia de la familia. Unos "
    "cuantos camastros situados en las paredes hacen las veces de lugar de "
    "descanso para los guardias. Al oeste está la salida del dormitorio.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"cama","camas","camastro","camastros"}),"Son unas tablas de "
    "maderas adosadas a la pared con un colchón encima.\n");
    AddExit("oeste","./guardia_cuarto");
    AddDoor("oeste", "una puerta",
    "Una puerta que comunica el dormitorio de los guardias con la sala de descanso.\n",
    ({"puerta", "puerta del oeste", "puerta de la sala de descanso"}));
}