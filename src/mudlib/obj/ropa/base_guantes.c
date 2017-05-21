/*
Fichero: base_guantes.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para los guantes de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_GUANTES, 0, P_SIZE_GENERIC, M_CUERO);
    }