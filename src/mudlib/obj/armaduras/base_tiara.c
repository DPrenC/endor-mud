/*
Fichero: base_tiara.c
Autor: Orome
Fecha: 27/07/2013
Descripción: archivo base para las  piezas de cabeza de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TIARA, 0, P_SIZE_GENERIC, M_COBRE);
    }