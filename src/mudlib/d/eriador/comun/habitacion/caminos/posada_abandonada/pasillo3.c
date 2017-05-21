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
    SetIntShort("el pasillo de los dormitorios");
    SetIntLong("Est�s al final del pasillo de los dormitorios de la casa de "
    "la familia Fhainfos.\n Al sur se entra a una peque�a sala de estar. Al norte "
    "est� la puerta del �ltimo dormitorio de la familia. El pasillo contin�a "
    "hacia el este.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("norte","./dormitorio1");
    AddExit("este","./pasillo2");
    AddExit("sur","./salita");
    AddDoor("sur", "la puerta de la sala de estar.\n",
    "Una puerta de madera para entrar a la sala de estar.\n",
    ({"puerta", "puerta del sur", "puerta de la sala de estar"}));
    AddDoor("norte", "una puerta", "Una simple puerta de madera.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
}
