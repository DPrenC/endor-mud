/*
Fichero: base_pulsera.c
Autor: Aule
Fecha: 29/6/2013
Descripci�n: archivo base para las  piezas de mu�eca de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_PULSERA, 0, P_SIZE_GENERIC, M_COBRE);
    }