/****************************************************************************
Fichero: maza.c
Autor: Ratwor
Fecha: 04/11/2007
Descripción: Una maza para los ogros.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>

inherit "std/weapon";

create()
{
    ::create();
    SetStandard(WT_MAZA,11,P_SIZE_LARGE,M_ACERO);
    SetShort("una gran maza");

    SetNumberHands(2);
    SetLong("  Es una gran maza de aspecto inmanejable.  Está constituida por un "
    "grueso mango de madera endurecida al fuego con una punta afilada en un extremo y "
    "una cabeza  esférica de hierro, con varias puntas cónicas, para causar mas daño "
    "al golpear con ella en el otro.\n");
    AddId(({"maza", "gran maza"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
}

