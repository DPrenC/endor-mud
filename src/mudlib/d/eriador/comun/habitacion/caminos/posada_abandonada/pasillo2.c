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
    SetIntLong("Estás en el centro del pasillo de los dormitorios de la casa "
    "Fhainfos. Al norte de aquí está una puerta de uno de los dormitorios de la "
    "familia. El pasillo transcurre de este a oeste.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("norte","./dormitorio2");
    AddExit("este","./pasillo1");
    AddExit("oeste","./pasillo3");
    AddDoor("norte", "una puerta", "Una simple puerta de madera.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
}
