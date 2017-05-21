/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntBright(50);
    SetIntShort("el hall de la casa de la familia Benjus");
    SetIntLong("Est�s en el r�stico hall de la entrada de la casa de la noble "
    "familia Benjus. El edificio es una r�stica casa de madera cuyos pilares son "
    "enormes troncos de manzano.\n  La estancia contin�a al norte hacia el gran sal�n.\n "
    "Al sur est� la salida a la calle de las cosechas.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");

    AddExit("norte",ENALHAB"poblado/casas/benjus/salon");
    AddExit("sur",ENALHAB"poblado/calles/calle16");
    AddDoor("sur", "la puerta de la calle",
    "Es la puerta de salida a la calle de las cosechas.\n",
    ({"puerta", "puerta de salida", "puerta de la calle", "puerta del sur"}));
}