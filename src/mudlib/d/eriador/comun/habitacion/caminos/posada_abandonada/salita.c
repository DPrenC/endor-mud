/*****************************************************************************
 AUTOR:		orome
 DETALLES:	una posada abandonada
 *****************************************************************************/

#include "./path.h"

inherit ROOM;

create() {
    ::create();

    SetIntBright(20);
    SetLocate("una posada abandonada");
    SetIntShort("la sala de estar");
    SetIntLong("Estás en una pequeña sala de estar para uso y disfrute privado "
    "de los miembros de la familia. Unos cómodos sofás y una mesita son el único "
    "moviliario de la salita. Al norte se encuentra el pasillo y al este una puerta "
    "comunica con la biblioteca de la familia.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"sofa","sofá","sofas","sofás"}),"Son unos sofás de piel muy cómodos.\n");
    AddDetail(({"mesa","mesita","mesilla"}),"Es una mesita de madera muy clara y elegante.\n");
    AddExit("norte","./pasillo3");
    AddExit("este","./biblioteca");
    AddDoor("este", "la puerta de la biblioteca",
    "Una puerta de madera para pasar a la biblioteca.\n",
    ({"puerta", "puerta de la biblioteca", "puerta del este"}));
    AddDoor("norte", "la puerta del pasillo",
    "La puerta para salir de la estancia al pasillo.\n",
    ({"puerta", "puerta del pasillo", "puerta del norte"}));
}
