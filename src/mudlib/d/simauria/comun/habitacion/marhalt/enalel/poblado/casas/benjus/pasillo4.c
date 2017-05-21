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
    SetIntShort("el pasillo");
    SetIntLong("Estás en un pasillo de paredes de madera. Hay una habitación "
    "hacia el norte. El pasillo continúa hacia el este y el sur.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"pared","paredes","pared de madera","paredes de madera"}),"Las "
    "paredes de madera crean un ambiente confortable en este largo pasillo.\n");

    AddExit("norte",ENALHAB"poblado/casas/benjus/dormitorio3");
    AddExit("este",ENALHAB"poblado/casas/benjus/pasillo3");
    AddExit("sur",ENALHAB"poblado/casas/benjus/pasillo5");
    AddDoor("norte", "una puerta",
    "Es una puerta de madera de manzano que da entrada a una habitación.\n",
    ({"puerta", "puerta de la habitación", "puerta de la habitación", "puerta del norte"}));
}
