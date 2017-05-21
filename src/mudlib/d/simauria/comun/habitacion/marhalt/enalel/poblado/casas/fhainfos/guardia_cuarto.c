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
    SetIntShort("el cuarto de la guardia");
    SetIntLong("Estás en el cuarto de la guardia de la familia Fhainfos. "
    "Es un cuarto espacioso donde los guardias pasan su tiempo libre. Al oeste "
    "se encuentra el hall de entrada a la vivienda y al este, una pequeña puerta, "
    "comunica con los dormitorios de la guardia.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("oeste",ENALHAB"poblado/casas/fhainfos/hall");
    AddExit("este",ENALHAB"poblado/casas/fhainfos/guardia_dormitorio");
    AddDoor("oeste", "la puerta del hall",
    "Es la puerta que sale al hall de la casa.\n",
    ({"puerta", "puerta del hall", "puerta del oeste"}));
    AddDoor("este",  "la puerta del dormitorio",
    "Esta puerta da acceso al dormitorio de descanso de los guardias.\n",
    ({"puerta", "puerta del este", "puerta del dormitorio"}));
    AddItem(ENALPNJ"guardias/fhainfos",REFRESH_DESTRUCT,d2());
}
