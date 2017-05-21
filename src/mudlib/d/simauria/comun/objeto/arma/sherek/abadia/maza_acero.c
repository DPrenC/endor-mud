/****************************************************************************
Fichero: /d/simauria/comun/objeto/arma/sherek/abadia/maza_acero.c
Autor: Lug y Yalin
Fecha: 17/09/2006
Descripción: Maza de batalla para el abad.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_MAZA,10,P_SIZE_MEDIUM,M_ACERO);
    SetShort("una maza de acero");
    SetLong("Es una maza de acero, perfectamente pulida y artísticamente "
        "rematada.\nLleva el emblema de Sherek grabado en su superficie.\n");
    AddSubDetail(({"emblema"}),"Es la imagen de la diosa Sherek, una mujer "
        "con una serpiente enroscada en su brazo derecho, a la que decapita "
        "con una daga que sostiene en su mano izquierda.\n");
    SetIds(({"maza","maza de acero"}));
    SetNumberHands(1);
    SetQuality(100);
    SetResetQuality(100);
}

