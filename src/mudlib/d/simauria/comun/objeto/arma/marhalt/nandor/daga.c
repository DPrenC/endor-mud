/****************************************************************************
Fichero: daga.c
Autor: Ratwor
Fecha: 06/04/2008
Descripci�n: una daga normal.
****************************************************************************/

#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit WEAPON;

create() {
    ::create();
    SetStandard(WT_CUCHILLO, 3, P_SIZE_LARGE, M_ACERO);
    AddId(({"daga","arma", "daga de acero",}));
    SetShort("una daga");
    SetLong("Es una daga de acero reluciente, con la hoja bien afilada y la empu�adura "
    "de madera de �bano.\n");
    SetValue(QueryValue()*2);
    Set(P_GENDER,GENDER_FEMALE);
    SetWeight(400);
}
