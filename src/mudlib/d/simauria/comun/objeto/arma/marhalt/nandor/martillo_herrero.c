/****************************************************************************
Fichero: martillo_herrero.c
Autor: Ratwor
Fecha: 25/04/2010
Descripción: un simple martillo de herrero
****************************************************************************/


#include <properties.h>
#include <combat.h>
#include <materials.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_MAZA, 7, P_SIZE_LARGE, M_HIERRO);
    SetShort("un martillo de herrero");
    SetLong("Es un enorme martillo de herrero.\n");
    AddId(({"martillo", "martillo de herrero"}));
    AddAdjective(({"pesado", "enorme"}));
    SetWeight(5500);
}

