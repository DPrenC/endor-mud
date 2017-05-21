/*
Fichero: base_pantalones.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para las prendas de las piernas en   Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_PANTALONES, 0, P_SIZE_GENERIC, M_TELA);
    }