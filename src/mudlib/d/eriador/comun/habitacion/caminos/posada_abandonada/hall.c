/*****************************************************************************
 AUTOR:		orome
 DETALLES:	hall de la posada abandonada
 *****************************************************************************/

#include "./path.h"

inherit ROOM;

create() {
    ::create();

    SetIntBright(20);
    SetLocate("una posada abandonada");
    SetIntShort("el hall de la casa de la familia Fhainfos");
    SetIntLong("Estás en el hall de la entrada de la casa de la noble familia "
    "Fhainfos. Es una suntuosa vivienda con adornos relacionados con la naturaleza. "
    "Una enorme puerta de noble madera comunica al sur con el salón principal.\n "
    "Al este, una pequeña puerta, comunica con el cuarto de la guardia de la familia.\n "
    "Al norte está la salida a la calle del comercio.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddExit("norte",CAMINO_ESTE_ERIADOR1("camino1_05"));
    //AddExit("este","./guardia_cuarto");
    AddExit("sur","./salon1");
    AddDoor("sur", "una gran puerta",
    "Es una enorme puerta que comunica esta estancia con el gran salón de la casa.\n",
    ({"puerta", "gran puerta", "puerta del sur", "puerta del salon", "puerta del salón"}));
    //AddDoor("este", "una pequeña puerta",
    //"Es la puerta del cuarto de la guardia personal de la familia.\n",
    //({"puerta", "puerta del este", "pequeña puerta", "puerta pequeña"}));
    //AddDoor("norte", "la puerta de la calle",
    //"La puerta de salida de la casa que da a la calle del comercio.\n",
    //({"puerta", "puerta de salida", "puerta de la calle", "puerta del norte"}));

}
