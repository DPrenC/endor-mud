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
    SetIntLong("Estás en uno de los dormitorios de la familia Prialane. Es una "
    "estancia de tonos oscuros y muebles desvencijados. La cama, junto con el "
    "resto de mobiliario, están sin orden por toda la habitación. La salida está "
    "hacia el norte.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"cama","mobiliario","mueble","muebles"}),"Los muebles de este "
    "cuarto parecen muy usados.\n");

    AddExit("norte",ENALHAB"poblado/casas/prialanes/pasillo");
    AddDoor("norte", "la puerta del pasillo",
    "La puerta para salir de la habitación.\n",
    ({"puerta", "puerta de salida", "puerta del pasillo", "puerta del norte"}));
}
