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
    SetIntLong("Est�s al comienzo del pasillo de los dormitorios de la casa "
    "Fhainfos Al norte est� uno de los dormitorios de la familia. El pasillo "
    "contin�a hacia el oeste.\n La escalera de bajada est� aqu�.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("norte","./dormitorio3");
    AddExit("oeste","./pasillo2");
    AddExit("abajo","./comedor");
    AddDoor("norte", "una puerta", "Una simple puerta de madera.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
}
