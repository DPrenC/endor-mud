/****************************************************************************
Fichero: escarpines.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: unos escarpines.
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
    SetShort("unos delicados escarpines");
    SetLong("Se trata de un calzado femenino fino y delicado. Realizado en la más fina "
    "piel, están rematados en los bordes con unas florecillas bordadas.\n");
    SetIds(({"zapatos", "escarpines", "delicados escarpines", "escarpines delicados"}));
    Set(P_GENDER, GENDER_MALE);
    Set(P_NUMBER, NUMBER_PLURAL);
    SetWeight(300);
    SetValue(1900);
}
