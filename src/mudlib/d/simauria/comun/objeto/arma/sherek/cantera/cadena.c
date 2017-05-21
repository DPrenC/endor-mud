/****************************************************************************
Fichero: /d/simauria/comun/objeto/arma/sherek/cantera/cadena.c
Autor: Yalin
Fecha: 18/04/2008 13:22
Descripci�n: cadena que llevan las ni�as demonias.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_CADENA,5,P_SIZE_GENERIC,M_ACERO);
    SetShort("una pesada cadena");
    SetLong("Es una cadena larga y pesada, probablemente encontrada en alg�n vertedero, o "
        "robada de alguna puerta. Es un arma tosca, pero podr�a hacerte mucho da�o.\n");
    AddId(({"cadena","cadena pesada","pesada cadena"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(1);
}
