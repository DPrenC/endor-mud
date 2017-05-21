/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Casa Prialanes");
    SetIntShort("un dormitorio");
    SetIntLong("Estás en uno de los dormitorios de la familia Prialane. Es un "
    "dormitorio de tonos verdosos y muebles metálicos. La cama es el único "
    "mobiliario aparente de la sala. La salida está hacia el nordeste.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"cama","mobiliario","mueble","muebles"}),"La cama, aunque muy "
    "cómoda, es el único mobiliario de la habitación.\n");

    AddExit("nordeste",ENALHAB"poblado/casas/prialanes/pasillo");
    AddDoor("nordeste", "la puerta del pasillo",
    "La puerta para salir de la habitación.\n",
    ({"puerta", "puerta de salida", "puerta del pasillo", "puerta del nordeste"}));
}
