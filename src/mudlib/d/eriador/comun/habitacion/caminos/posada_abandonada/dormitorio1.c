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
    SetIntShort("un dormitorio");
    SetIntLong("Est�s en uno de los dormitorios de la familia. La decoraci�n "
    "es abundante y delicada. La enorme cama ocupa el centro de la habitaci�n. "
    "Al sur est� la salida al pasillo.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail("cama","Es una enorme cama de aspecto muy c�modo.\n");
    AddExit("sur","./pasillo3");
    AddDoor("sur", "la puerta del pasillo",
    "Una puerta de madera para salir de la habitaci�n.\n",
    ({"puerta", "puerta del sur", "puerta del pasillo"}));
}
