/****************************************************************************
Fichero: sandalias.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: unas lujosas sandalias.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create()
{
    ::create();
    switch(d2()){
        case 1: SetStandard(AT_BOTAS, 1, P_SIZE_MEDIUM, M_PIEL); break;
        case 2: SetStandard(AT_BOTAS, 1, P_SIZE_SMALL, M_PIEL); break;
    }

    SetShort("unas lujosas sandalias");
    SetLong("Se trata de unas estilizadas sandalias atadas con cintas de colores hasta "
    "la parte superior de la pantorrilla. Realizadas en fina piel y con incrustaciones "
    "de piedras preciosas.\n");
    SetIds(({"sandalias", "estilizadas sandalias", "sandalias estilizadas", "sandalias lujosas",
        "lujosas sandalias"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL);
    SetValue(700);
}
