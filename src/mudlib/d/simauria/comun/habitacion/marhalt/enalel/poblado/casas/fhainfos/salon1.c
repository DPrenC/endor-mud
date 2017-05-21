/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(40);
    SetLocate("Casa Fhainfos");
    SetIntShort("el salón principal");
    SetIntLong("Estás en el enorme salón principal de la familia Fhainfos. "
    "Multitud de fiestas y reuniones se han celebrado en este enorme salón. "
    "La decoración está dominada por el tema de la naturaleza, con bellos "
    "tapices en las paredes, y bellos muebles de nobles maderas. Hacia el "
    "norte, una enorme puerta de madera comunica con el hall de entrada de "
    "la vivienda. Hay dos pequeñas puertas situadas hacia el este y el oeste.\n "
    "Hacia el sur se extiende el salón.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"decoracion","decoración","tapiz","tapices","mueble","muebles"}),
    "Enormes tapices de suntuosas escenas en bosques mágicos y hermosos muebles "
    "con grabados naturistas componen la decoración de la sala.");
    AddExit("norte",ENALHAB"poblado/casas/fhainfos/hall");
    AddExit("este",ENALHAB"poblado/casas/fhainfos/despacho_anciano");
    AddExit("sur",ENALHAB"poblado/casas/fhainfos/salon2");
    AddExit("oeste",ENALHAB"poblado/casas/fhainfos/cocina");
    AddDoor("oeste", "la puerta de la cocina",
    "Una pequeña puerta que comunica con la cocina.\n",
    ({"puerta", "puerta de la cocina", "puerta del oeste"}));
    AddDoor("este", "una puerta", "Una puerta normal de madera",
    ({"puerta", "puerta del este", "puerta de madera"}));
    AddDoor("norte", "la puerta de salida",
    "Es la puerta para salir del salón, da al hall de la casa.\n",
    ({"puerta", "puerta de salida", "puerta del hall", "puerta del norte"}));
    AddItem(ENALPNJ"otros/criado",REFRESH_DESTRUCT);
}
