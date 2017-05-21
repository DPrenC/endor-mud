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
    SetIntShort("el pasillo de los dormitorios");
    SetIntLong("Estás en un extrecho pasillo de paredes claras y techo bajo. "
    "Cuadros y retratos lo adornan agradablemente.\n El salón está hacia "
    "el norte.\n Al sur, suroeste y oeste hay tres puertas que comunican con los "
    "distintos dormitorios de la familia.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"pared","paredes"}),"Son paredes de una tonalidad clara distinta "
    "al de el resto de la casa.\n");
    AddDetail(({"cuadro","cuadros","retrato","retratos"}),"Son los distintos "
    "retratos de grandes personajes de esta familia, todos famosos alquimistas, "
    "brujos o magos.\n");

    AddExit("norte",ENALHAB"poblado/casas/prialanes/salon");
    AddExit("sur",ENALHAB"poblado/casas/prialanes/dormitorio1");
    AddExit("suroeste",ENALHAB"poblado/casas/prialanes/dormitorio2");
    AddExit("oeste",ENALHAB"poblado/casas/prialanes/dormitorio3");
    AddDoor("sur", "la puerta de un dormitorio",
    "La puerta de uno de los dormitorios de la mansión.\n",
    ({"puerta", "puerta del sur"}));
    AddDoor("suroeste", "la puerta de un dormitorio",
    "La puerta de uno de los dormitorios de la mansión.\n",
    ({"puerta", "puerta del suroeste"}));
    AddDoor("oeste", "la puerta de un dormitorio",
    "La puerta de uno de los dormitorios de la mansión.\n",
    ({"puerta", "puerta del oeste"}));
}
