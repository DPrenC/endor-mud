/*
Fichero: base_grebas.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para las armaduras para las piernas  de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_GREBAS, 1, P_SIZE_GENERIC, M_CUERO);
    }