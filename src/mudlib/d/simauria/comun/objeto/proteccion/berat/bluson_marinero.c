/****************************************************************************
Fichero: bluson_marinero.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: un blusón blanco
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TABARDO, 1, P_SIZE_GENERIC, M_TELA);
    SetShort("un blusón blanco");
    SetLong("Ess un blusón blanco de tela que suelen utilizar mucho algunos "
    "marineros.\n Presenta desgarros y manchas en algunas zonas.\n");
    SetIds(({"bluson", "blusón", "ropa"}));
    AddAdjective(({"blanco", "de", "tela", "marinero"}));
    SetWeight(500);
    Set(P_GENDER, GENDER_MALE);

}
