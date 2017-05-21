/*
Fichero: base_escudo.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para los escudos  de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_ESCUDO, 1, P_SIZE_GENERIC, M_CUERO);
    }