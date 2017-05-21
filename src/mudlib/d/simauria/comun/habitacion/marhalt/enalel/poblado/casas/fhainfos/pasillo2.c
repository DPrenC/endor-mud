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
    SetIntLong("Estás en el centro del pasillo de los dormitorios de la casa "
    "Fhainfos. Al norte de aquí está una puerta de uno de los dormitorios de la "
    "familia. El pasillo transcurre de este a oeste.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("norte",ENALHAB"poblado/casas/fhainfos/dormitorio2");
    AddExit("este",ENALHAB"poblado/casas/fhainfos/pasillo1");
    AddExit("oeste",ENALHAB"poblado/casas/fhainfos/pasillo3");
    AddDoor("norte", "una puerta", "Una simple puerta de madera.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
}
