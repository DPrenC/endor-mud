/*
Fichero: base_tabardo.c
Autor: Ulmo
Fecha: 28/7/2013
Descripción: archivo base para los tabardos de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TABARDO, 1, P_SIZE_GENERIC, M_CUERO);
    }