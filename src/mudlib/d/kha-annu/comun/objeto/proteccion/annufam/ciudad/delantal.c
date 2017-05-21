/***************************************************************************
Archivo: delantal.c
autor: Riberales
Creación: 03/10/2005
Descripción: El delantal de la posadera.
***************************************************************************/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <colours.h>
inherit "std/armour";



public void create()
{
    ::create();
    SetStandard(AT_TABARDO,2,P_SIZE_NORMAL,M_TELA);
    AddId(({"delantal","armadura","delantal blanco"}));
    SetShort("Un delantal blanco");
    SetLong(W("Es un delantal de color "+TC_WHITE+"blanco"+TC_NORMAL+", y no muy sucio.\n"));
    Set(P_GENDER, GENDER_MALE);
}
