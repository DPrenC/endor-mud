/*
Fichero: base_amuleto.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para los objetos para vestir en el cuello  de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_AMULETO, 0, P_SIZE_GENERIC, M_COBRE);
    }