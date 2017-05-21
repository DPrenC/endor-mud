/****************************************************************************
Fichero: chaleco_roorg_f.c
Autor: Ratwor
Fecha: 29/06/2010
Descripción: un chaleco de piel de roorg para mujeres.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TABARDO, 1, P_SIZE_LARGE, M_PIEL);
    SetShort("un chaleco de piel de roorg");
    SetLong("Es un chaleco confeccionado con la liviana piel escamosa del pez "
    "carnívoro conocido como roorg.\n Esta versión femenina de la prenda local "
    "se distingue de la masculina en que exhibe un pronunciado escote en la parte "
    "frontal, y en los vivos colores con los que la piel está teñida.\n");
    SetIds(({"chaleco", "ropa"}));
    AddAdjective(({"de", "piel", "roorg", "femenino"}));
    SetWeight(400);
    Set(P_GENDER, GENDER_MALE);

}
