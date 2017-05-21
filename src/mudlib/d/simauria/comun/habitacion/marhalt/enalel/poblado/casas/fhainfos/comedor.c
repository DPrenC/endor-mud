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
    SetIntShort("el comedor");
    SetIntLong("Estás en una enorme sala con una larga mesa en el centro "
    "donde se celebran fastuosos banquetes. Una escalera comunica con el piso "
    "superior. Hacia el oeste se encuentra el salón principal.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("oeste",ENALHAB"poblado/casas/fhainfos/salon2");
    AddExit("arriba",ENALHAB"poblado/casas/fhainfos/pasillo1");
    AddDoor("oeste", "la puerta del salón",
    "La puerta que comunica el gran salón con el comedor.\n",
    ({"puerta", "puerta del oeste", "puerta del salón", "puerta del salon"}));
    AddItem(ENALPNJ"guardias/fhainfos",REFRESH_DESTRUCT,1);
}
