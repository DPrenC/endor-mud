/****************************************************************************
Fichero: /d/simauria/comun/objeto/arma/sherek/cantera/cadena.c
Autor: Yalin
Fecha: 18/04/2008 13:22
Descripción: cadena que llevan las niñas demonias.
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
    SetLong("Es una cadena larga y pesada, probablemente encontrada en algún vertedero, o "
        "robada de alguna puerta. Es un arma tosca, pero podría hacerte mucho daño.\n");
    AddId(({"cadena","cadena pesada","pesada cadena"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(1);
}
