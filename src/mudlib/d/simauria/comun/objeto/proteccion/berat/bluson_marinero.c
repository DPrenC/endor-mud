/****************************************************************************
Fichero: bluson_marinero.c
Autor: Ratwor
Fecha: 14/05/2010
Descripci�n: un blus�n blanco
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TABARDO, 1, P_SIZE_GENERIC, M_TELA);
    SetShort("un blus�n blanco");
    SetLong("Ess un blus�n blanco de tela que suelen utilizar mucho algunos "
    "marineros.\n Presenta desgarros y manchas en algunas zonas.\n");
    SetIds(({"bluson", "blus�n", "ropa"}));
    AddAdjective(({"blanco", "de", "tela", "marinero"}));
    SetWeight(500);
    Set(P_GENDER, GENDER_MALE);

}
