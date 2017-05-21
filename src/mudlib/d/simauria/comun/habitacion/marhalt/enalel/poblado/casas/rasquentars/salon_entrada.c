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
    SetIntShort("el salón de entrada");
    SetIntLong("Estás en un enorme salón donde la familia recibe a las visitas. "
    "Los muebles y cuadros que aquí se encuentran crean una atmósfera recargada y "
    "opresiva.\n Al este de aquí se encuentra la entrada al cuarto de la guardia y "
    "al norte está la entrada al comedor. Al oeste está la salida de la vivienda.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"mueble","muebles","decoración","decoracion"}),"Son muebles de "
    "tonos oscuros y de estilo recargado y obstentoso.\n");
    AddDetail(({"cuadro","cuadros"}),"Los cuadros representan escénas épicas "
    "realizadas por los miembros importantes de la familia.\n");
    AddExit("norte",ENALHAB"poblado/casas/rasquentars/comedor");
    AddExit("este",ENALHAB"poblado/casas/rasquentars/cuarto_guardia");
    AddExit("oeste",ENALHAB"poblado/casas/rasquentars/hall");
    AddDoor("norte", "la puerta del comedor",
    "Es una puerta mediana para acceder al comedor de la casa.\n",
    ({"puerta", "puerta del comedor", "puerta del norte"}));
    AddDoor("oeste", "la puerta del hall",
    "La puerta que da salida al hall de la vivienda.\n",
    ({"puerta", "puerta del hall", "puerta del oeste"}));
    AddDoor("este", "la puerta de la guardia",
    "Es una puerta que da acceso a la sala de descanso de la guardia de la familia.\n",
    ({"puerta", "puerta del este", "puerta de la guardia"}));
    AddItem(ENALPNJ"guardias/rasquentars",REFRESH_DESTRUCT,1);
}
