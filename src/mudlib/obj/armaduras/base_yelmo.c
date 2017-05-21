/*
Fichero: base_yelmo.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para los brazales de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_CASCO, 1, P_SIZE_GENERIC, M_CUERO);
    }