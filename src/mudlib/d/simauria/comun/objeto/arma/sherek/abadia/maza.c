/****************************************************************************
Fichero: /d/simauria/comun/objeto/arma/sherek/abadia/maza.c
Autor: Lug y Yalin
Fecha: 17/09/2006
Descripción: Maza de batalla para los novicios.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_MAZA,3,P_SIZE_MEDIUM,M_MADERA);
    SetShort("una maza de madera");
    SetLong("Es una maza de madera, finamente labrada.\nEs un arma sencilla, "
        "pero eficaz.\n");
    SetIds(({"maza","maza de madera"}));
    SetNumberHands(1);
    SetQuality(100);
    SetResetQuality(100);
}

