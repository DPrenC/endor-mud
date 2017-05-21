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
    SetIntShort("el pasillo de los dormitorios");
    SetIntLong("Estás al comienzo del pasillo de los dormitorios de la casa "
    "Fhainfos Al norte está uno de los dormitorios de la familia. El pasillo "
    "continúa hacia el oeste.\n La escalera de bajada está aquí.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("norte","./dormitorio3");
    AddExit("oeste","./pasillo2");
    AddExit("abajo","./comedor");
    AddDoor("norte", "una puerta", "Una simple puerta de madera.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
}
