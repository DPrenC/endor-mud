/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Poblado de Enalel");
    SetIntShort("un dormitorio");
    SetIntLong("Estás en uno de los dormitorios de la familia Rasquentar. "
    "La enorme cama ocupa el centro de la habitación. Al este está la salida.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail("cama","Es una enorme cama de madera. Parece muy cómoda.\n");
    AddExit("este",ENALHAB"poblado/casas/rasquentars/salon_visitas");
    AddDoor("este", "la puerta del salón",
    "La puerta para salir del dormitorio.\n",
    ({"puerta", "puerta del este", "puerta de salida", "puerta del salon",
        "puerta del salón"}));
}
