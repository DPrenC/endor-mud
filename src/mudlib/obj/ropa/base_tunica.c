/*
Fichero: base_tunica.c
Autor: Aule
Fecha: 29/6/2013
Descripción: archivo base para las prendas de ropa para la parte superior del cuerpo  de Endor
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TUNICA, 0, P_SIZE_GENERIC, M_TELA);
    }