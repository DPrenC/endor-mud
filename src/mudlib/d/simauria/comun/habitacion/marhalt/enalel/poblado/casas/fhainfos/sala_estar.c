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
    SetIntShort("la sala de estar");
    SetIntLong("Estás en una pequeña sala de estar para uso y disfrute privado "
    "de los miembros de la familia. Unos cómodos sofás y una mesita son el único "
    "moviliario de la salita. Al norte se encuentra el pasillo y al este una puerta "
    "comunica con la biblioteca de la familia.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"sofa","sofá","sofas","sofás"}),"Son unos sofás de piel muy cómodos.\n");
    AddDetail(({"mesa","mesita","mesilla"}),"Es una mesita de madera muy clara y elegante.\n");
    AddExit("norte",ENALHAB"poblado/casas/fhainfos/pasillo3");
    AddExit("este",ENALHAB"poblado/casas/fhainfos/biblioteca");
    AddDoor("este", "la puerta de la biblioteca",
    "Una puerta de madera para pasar a la biblioteca.\n",
    ({"puerta", "puerta de la biblioteca", "puerta del este"}));
    AddDoor("norte", "la puerta del pasillo",
    "La puerta para salir de la estancia al pasillo.\n",
    ({"puerta", "puerta del pasillo", "puerta del norte"}));
}
