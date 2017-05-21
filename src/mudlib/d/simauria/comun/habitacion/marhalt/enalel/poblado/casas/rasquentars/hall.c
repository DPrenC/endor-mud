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
    SetIntShort("el hall de la casa de la familia Rasquentars");
    SetIntLong("Estás en el hall de la entrada de la casa de la poderosa "
    "familia Rasquentars. Es un edificio de una sola planta pero de proporciones "
    "desmesuradas. Los enormes muros son de piedra oscura. Una puerta de madera maciza "
    "situada al este permite la entrada a la casa.\n Al sur está la salida hacia "
    "la calle de la empalizada.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail(({"muro","muros"}),"Son unos enormes muros de piedra oscura que "
    "protegen la casa de la familia.\n");
    AddExit("este",ENALHAB"poblado/casas/rasquentars/salon_entrada");
    AddExit("sur",ENALHAB"poblado/calles/calle12");
    AddDoor("este", "la puerta del salón",
    "Es la puerta que da acceso al salón de la vivienda.\n",
    ({"puerta", "puerta del salón", "puerta del salon", "puerta del este"}));
    AddItem(ENALPNJ"guardias/rasquentars",REFRESH_DESTRUCT,d2());
}