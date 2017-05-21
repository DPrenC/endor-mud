/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Casa Benjus");
    SetIntShort("un dormitorio");
    SetIntLong("Estás en un rústico dormitorio. La decoración y el mobiliario "
    "es simple pero elegante. La cama preside la estancia.\n El pasillo está hacia "
    "el sur.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"cama","muebles","mueble","moviliario"}),"Todo en este dormitorio "
    "está hecho de la mejor madera que se pueda encontrar.\n");

    AddExit("sur",ENALHAB"poblado/casas/benjus/pasillo2");
    AddDoor("sur", "una puerta",
    "Es una puerta de madera que da salida al pasillo.\n",
    ({"puerta", "puerta del pasillo", "puerta del sur"}));
}
