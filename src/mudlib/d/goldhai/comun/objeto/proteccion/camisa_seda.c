/*=============================================================*
/****************************************************************************
Fichero: camisa_seda.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: una camisa blanca de seda
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create() {
    ::create();
    switch(d2()){
        case 1: SetStandard(AT_TUNICA,0,P_SIZE_MEDIUM,M_TELA); break;
        case 2: SetStandard(AT_TUNICA,0,P_SIZE_SMALL,M_TELA); break;
    }

    SetIds(({"camisa", "camisa blanca", "camisa de seda"}));
    SetShort("una camisa blanca de seda");
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetLong("Se trata de una camisa de la mas fina seda élfica. Sus  mangas abullonadas "
    "y los encajes de sus puños constatan a las claras que se trata de la camisa de "
    "alguien con gran elegancia.\n");


    SetWeight(450);
    SetValue(3500);
}
