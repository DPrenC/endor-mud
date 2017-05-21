/*****************************************************************************
 AUTOR:		orome
 DETALLES:	un comedor de la posada abandonada
 *****************************************************************************/

#include "./path.h"

inherit ROOM;

create() {
    ::create();

    SetIntBright(20);
    SetLocate("una posada abandonada");
    SetIntShort("el comedor");
    SetIntLong("Est�s en una enorme sala con una larga mesa en el centro "
    "donde se celebran fastuosos banquetes. Una escalera comunica con el piso "
    "superior. Hacia el oeste se encuentra el sal�n principal.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("oeste","./salon2");
    AddExit("arriba","./pasillo1");
    AddDoor("oeste", "la puerta del sal�n",
    "La puerta que comunica el gran sal�n con el comedor.\n",
    ({"puerta", "puerta del oeste", "puerta del sal�n", "puerta del salon"}));

}
