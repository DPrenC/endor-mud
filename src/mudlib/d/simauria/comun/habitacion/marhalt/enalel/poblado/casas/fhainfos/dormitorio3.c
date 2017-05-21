/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Casa Fhainfos");
    SetIntShort("un dormitorio");
    SetIntLong("Est�s en uno de los dormitorios de la familia. La �nica "
    "decoraci�n es una l�mpara que cuelga del techo. La enorme cama ocupa el "
    "centro de la habitaci�n. Al sur est� la salida al pasillo.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail("cama","Es una enorme cama de aspecto muy c�modo.\n");
    AddDetail(({"l�mpara", "lampara"}),"Es una l�mpara de techo que se asemeja a la "
    "copa de un manzano.\n");
    AddExit("sur",ENALHAB"poblado/casas/fhainfos/pasillo1");
    AddDoor("sur", "la puerta del pasillo",
    "Una puerta de madera para salir de la habitaci�n.\n",
    ({"puerta", "puerta del sur", "puerta del pasillo"}));
}
