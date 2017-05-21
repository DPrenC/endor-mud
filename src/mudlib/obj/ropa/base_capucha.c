/*
Fichero: base_capucha.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para las capuchas de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_CAPUCHA, 0, P_SIZE_GENERIC, M_TELA);
    }