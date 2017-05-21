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
    SetIntShort("el cuarto de la guardia");
    SetIntLong("Est�s en el cuarto de la guardia de la familia Rasquentar. Las "
    "camas se apilan en un lateral para hacer espacio al sitio de entrenamiento. "
    "La puerta de salida est� al oeste.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"cama","camas"}),"Las camas se encuentran apiladas en un lateral "
    "de la habitaci�n.\n");

    AddExit("oeste",ENALHAB"poblado/casas/rasquentars/salon_entrada");
    AddDoor("oeste", "la puerta del sal�n",
    "Es la puerta para salir del cuarto de la guardia.\n",
    ({"puerta", "puerta del oeste", "puerta del sal�n", "puerta del salon"}));
    AddItem(ENALPNJ"guardias/rasquentars",REFRESH_DESTRUCT,d2());
}
