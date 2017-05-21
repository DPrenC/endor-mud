/****************************************************************************
Fichero: daga_negra.c
Autor: Ratwor
Fecha: 06/04/2008
Descripción: Una daga negra para Shafil.
****************************************************************************/

#include <combat.h>
#include "./path.h"
#include <properties.h>
#include <combat.h>
inherit WEAPON;

create()
{
    if (!clonep(TO)) return 1;
    ::create();
    SetStandard(WT_CUCHILLO,3,P_SIZE_MEDIUM,M_ACERO);
    SetWeight(520);
    SetShort("una daga negra");
    AddId(({"daga_negra_tabernera", "daga","daga negra", "daga corta"}));
    SetValue(QueryValue()*2);
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(1);
    SetLong("Es una reluciente daga corta de metal negro y empuñadura de plata, "
            "lleva una rosa cincelada en la hoja.\n");
    AddSubDetail(({"rosa", "rosa cincelada", "hoja"}), "En la reluciente hoja de acero "
    "negro hay una bonita rosa cincelada de apenas un centímetro de tamaño.\n");
}
