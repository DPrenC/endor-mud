/*
Fichero: base_manto.c
Autor: Aule
Fecha: 29/6/2013
Descripci�n: archivo base para los mantos de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_MANTO, 0, P_SIZE_GENERIC, M_TELA);
    }