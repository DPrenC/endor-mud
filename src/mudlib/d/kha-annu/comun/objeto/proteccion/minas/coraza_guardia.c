/****************************************************************************
Fichero: coraza_guardia.c
Autor: Riberales
Fecha: 05/02/2006
Descripción: Una coraza para los guardias mineros. Sólo lleva lo común a las
             tres plantas.
****************************************************************************/


#include "path.h"
#include <combat.h>
#include <properties.h>

inherit ARMOUR;

create()
{
    ::create();

    SetStandard(AT_CORAZA,1,P_SIZE_MEDIUM,M_ACERO);
    SetShort("una coraza enana");

    SetIds(({"coraza","coraza enana","armadura","coraza de acero"}));
}

