/*
Fichero: base_botas.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para el calzado de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_GENERIC, M_CUERO);
    }