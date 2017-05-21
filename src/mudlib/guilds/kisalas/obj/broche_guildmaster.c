/****************************************************************************
Fichero: broche_guildmaster.c
Autor: Kastwey
Fecha: 29/03/2006
Descripción: El broche para la gran kisala
****************************************************************************/

#include <combat.h>
#include <size.h>
#include <materials.h>

inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_AMULET,0,P_SIZE_MEDIUM, M_ORO);
    SetShort("un broche de oro");
    SetLong("Es un broche de oro con una esmeralda engarzada, que sirve para recogerse el cabello.\n");
    SetIds(({"broche", "broche de oro"}));
    SetWeight(80);

}