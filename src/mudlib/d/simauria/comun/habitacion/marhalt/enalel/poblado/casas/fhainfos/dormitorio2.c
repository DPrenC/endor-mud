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
    SetIntLong("Estás en uno de los dormitorios de la familia. La decoración "
    "brilla por su ausencia. La enorme cama ocupa el centro de la habitación. "
    "Al sur está la salida al pasillo.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail("cama","Es una enorme cama de aspecto muy cómodo.\n");
    AddExit("sur",ENALHAB"poblado/casas/fhainfos/pasillo2");
    AddDoor("sur", "la puerta del pasillo",
    "Una puerta de madera para salir de la habitación.\n",
    ({"puerta", "puerta del sur", "puerta del pasillo"}));
}
