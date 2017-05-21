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
    SetIntLong("Estás en un pasillo de paredes de madera. Al norte y al sur "
    "hay dos habitaciones. El pasillo continúa hacia el este y el oeste.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"pared","paredes","pared de madera","paredes de madera"}),"Las "
    "paredes de madera crean un ambiente confortable en este largo pasillo.\n");

    AddExit("norte",ENALHAB"poblado/casas/benjus/dormitorio1");
    AddExit("sur",ENALHAB"poblado/casas/benjus/dormitorio2");
    AddExit("este",ENALHAB"poblado/casas/benjus/pasillo1");
    AddExit("oeste",ENALHAB"poblado/casas/benjus/pasillo3");
    AddDoor("norte", "una puerta",
    "Es una puerta de madera de manzano para entrar a la habitación del norte.\n",
    ({"puerta", "puerta de la habitación", "puerta de la habitacion", "puerta del norte"}));
    AddDoor("sur", "una puerta",
    "Es una puerta de madera de manzano para entrar a la habitación del sur.\n",
    ({"puerta", "puerta de la habitación", "puerta de la habitacion", "puerta del sur"}));

}
