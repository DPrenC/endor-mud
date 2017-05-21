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
    SetIntShort("el pasillo de los dormitorios");
    SetIntLong("Estás al comienzo del pasillo de los dormitorios de la casa "
    "Fhainfos Al norte está uno de los dormitorios de la familia. El pasillo "
    "continúa hacia el oeste.\n La escalera de bajada está aquí.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("norte",ENALHAB"poblado/casas/fhainfos/dormitorio3");
    AddExit("oeste",ENALHAB"poblado/casas/fhainfos/pasillo2");
    AddExit("abajo",ENALHAB"poblado/casas/fhainfos/comedor");
    AddDoor("norte", "una puerta", "Una simple puerta de madera.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
}
