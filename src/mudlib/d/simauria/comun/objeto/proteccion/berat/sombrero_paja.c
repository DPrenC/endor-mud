/****************************************************************************
Fichero: sombrero_paja.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: un sombrero de paja
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_CAPUCHA, 0, P_SIZE_LARGE, M_TELA);
    SetShort("un sombrero de paja");
    SetLong("Es un simple sombrero de paja sin nada especial.\n");
    SetIds(({"sombrero"}));
  AddAdjective(({"de", "paja"}));
    Set(P_GENDER, GENDER_MALE);
    SetWeight(200);
}
