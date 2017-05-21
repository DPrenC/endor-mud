/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Casa Prialanes");
    SetIntShort("el salón de la casa");
    SetIntLong("Estás en un enorme salón de altos techos y decoración recargada. "
    "En el centro de la sala una enorme mesa ocupa la mayor parte del espacio, "
    "y a su alrededor, se disponen multitud de sillas.\n Al sur, un pasillo comunica "
    "con los dormitorios, y al oeste se encuentran otras estancias de la casa. Al "
    "nordeste está la salida de la casa.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"mesa","silla","sillas"}),"Todos los muebles del salón son de "
    "madera rugosa y oscura.\n");

    AddExit("nordeste",ENALHAB"poblado/casas/prialanes/hall");
    AddExit("sur",ENALHAB"poblado/casas/prialanes/pasillo");
    AddExit("oeste",ENALHAB"poblado/casas/prialanes/cocina");
    AddDoor("oeste", "la puerta de la cocina",
    "La puerta para entrar en la cocina.\n",
    ({"puerta", "puerta de la cocina", "puerta del oeste"}));
}
