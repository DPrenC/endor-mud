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
    SetIntLong("Est�s en un pasillo de paredes de madera. Hay una habitaci�n "
    "hacia el norte. El pasillo contin�a hacia el este y el sur.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"pared","paredes","pared de madera","paredes de madera"}),"Las "
    "paredes de madera crean un ambiente confortable en este largo pasillo.\n");

    AddExit("norte",ENALHAB"poblado/casas/benjus/dormitorio3");
    AddExit("este",ENALHAB"poblado/casas/benjus/pasillo3");
    AddExit("sur",ENALHAB"poblado/casas/benjus/pasillo5");
    AddDoor("norte", "una puerta",
    "Es una puerta de madera de manzano que da entrada a una habitaci�n.\n",
    ({"puerta", "puerta de la habitaci�n", "puerta de la habitaci�n", "puerta del norte"}));
}
