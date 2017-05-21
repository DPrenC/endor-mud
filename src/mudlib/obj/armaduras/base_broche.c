/*
Fichero: base_broche.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para los broches u otros objetos para vestir en el cuello  de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_BROCHE, 0, P_SIZE_GENERIC, M_COBRE);
    }