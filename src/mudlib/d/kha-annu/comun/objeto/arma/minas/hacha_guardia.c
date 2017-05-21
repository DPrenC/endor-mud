/****************************************************************************
Fichero: hacha_guardia.c
Autor: Riberales
Fecha: 05/02/2006
Descripci�n: Una hacha para los guardianes de las minas, s�lo lleva lo com�n
             de las tres plantas.
****************************************************************************/


#include "path.h"
#include <combat.h>
#include <properties.h>

inherit WEAPON;



create()
{
    ::create();

    SetStandard(WT_HACHA,1,P_SIZE_MEDIUM,M_ACERO);
    SetShort("un hacha enana");

    SetIds(({"hacha","hacha enana"}));

    Set(P_GENDER, GENDER_FEMALE);
    SetNumberHands(1);

}
