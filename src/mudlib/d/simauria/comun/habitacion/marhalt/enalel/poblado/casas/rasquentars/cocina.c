/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Poblado de Enalel");
    SetIntShort("la cocina");
    SetIntLong("Estás en una enorme cocina llena de todo tipo de cacharros. "
    "Los fogones siempre están encendidos. La salida de la cocina está hacia "
    "el este.\n");
    SetIntSmell("Un aroma a ricas comidas invade esta habitación.\n");
    AddExit("este",ENALHAB"poblado/casas/rasquentars/comedor");
    AddDoor("este", "la puerta del comedor",
    "La puerta de la cocina que tiene salida al comedor de la vivienda.\n",
    ({"puerta", "puerta del comedor", "puerta del este"}));
}
