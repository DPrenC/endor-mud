/*
Fichero: base_talabarte.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para los talabartes de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TALABARTE, 0, P_SIZE_GENERIC, M_CUERO);
    }