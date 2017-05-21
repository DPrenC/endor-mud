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
    SetIntLong("Est�s en uno de los dormitorios de la familia Rasquentar. "
    "La enorme cama ocupa el centro de la habitaci�n. Al oeste est� la salida.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail("cama","Es una enorme cama de madera. Parece muy c�moda.\n");
    AddExit("oeste",ENALHAB"poblado/casas/rasquentars/salon_visitas");
    AddDoor("oeste", "la puerta del sal�n",
    "La puerta para salir del dormitorio.\n",
    ({"puerta", "puerta del oeste", "puerta de salida", "puerta del salon",
        "puerta del sal�n"}));
}
