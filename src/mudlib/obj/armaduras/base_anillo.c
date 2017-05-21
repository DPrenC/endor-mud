/*
Fichero: base_anillo.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para los anillos  de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_ANILLO, 0, P_SIZE_GENERIC, M_COBRE);
    }