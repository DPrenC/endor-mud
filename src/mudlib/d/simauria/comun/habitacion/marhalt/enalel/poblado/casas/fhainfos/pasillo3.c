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
    SetIntLong("Estás al final del pasillo de los dormitorios de la casa de "
    "la familia Fhainfos.\n Al sur se entra a una pequeña sala de estar. Al norte "
    "está la puerta del último dormitorio de la familia. El pasillo continúa "
    "hacia el este.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("norte",ENALHAB"poblado/casas/fhainfos/dormitorio1");
    AddExit("este",ENALHAB"poblado/casas/fhainfos/pasillo2");
    AddExit("sur",ENALHAB"poblado/casas/fhainfos/sala_estar");
    AddDoor("sur", "la puerta de la sala de estar.\n",
    "Una puerta de madera para entrar a la sala de estar.\n",
    ({"puerta", "puerta del sur", "puerta de la sala de estar"}));
    AddDoor("norte", "una puerta", "Una simple puerta de madera.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
}
