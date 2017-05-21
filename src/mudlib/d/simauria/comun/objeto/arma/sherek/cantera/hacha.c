/****************************************************************************
Fichero: /d/simauria/comun/objeto/arma/sherek/cantera/hacha.c
Autor: Yalin
Fecha: 17/04/2008 13:38
Descripci�n: hacha que llevan las demonias.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_HACHA,7,P_SIZE_GENERIC,M_ACERO);
    SetShort("una vieja hacha");
    SetLong("Es una vieja hacha, oxidada y sucia, probablemente encontrada en alg�n basurero. "
        "Hace a�os que la fabricaron, pero a�n puede romperte la cabeza.\n");
    AddId(({"hacha","hacha vieja","vieja hacha"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(1);
}
