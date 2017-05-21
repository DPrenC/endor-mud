/*****************************************************************************
 AUTOR:		orome
 DETALLES:	posada abandonada
 *****************************************************************************/

#include "./path.h"

inherit ROOM;

create() {
    ::create();

    SetIntBright(20);
    SetLocate("una posada abandonada");
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
    AddExit("norte","./hall");
    //AddExit("este","./despacho_anciano");
    AddExit("sur","./salon2");
    AddExit("oeste","./cocina");
    AddDoor("oeste", "la puerta de la cocina",
    "Una pequeña puerta que comunica con la cocina.\n",
    ({"puerta", "puerta de la cocina", "puerta del oeste"}));
    //AddDoor("este", "una puerta", "Una puerta normal de madera",
    //({"puerta", "puerta del este", "puerta de madera"}));
    AddDoor("norte", "la puerta de salida",
    "Es la puerta para salir del salón, da al hall de la casa.\n",
    ({"puerta", "puerta de salida", "puerta del hall", "puerta del norte"}));

}
