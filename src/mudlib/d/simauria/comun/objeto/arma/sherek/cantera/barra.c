/****************************************************************************
Fichero: /d/simauria/comun/objeto/arma/sherek/cantera/barra.c
Autor: Yalin
Fecha: 18/04/2008 13:22
Descripción: barra de hierro que llevan los niños demonios.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_VARA,6,P_SIZE_GENERIC,M_ACERO);
    SetShort("una barra de hierro");
    SetLong("Es una barra de hierro larga y gruesa, probablemente encontrada entre la escoria "
        "de alguna forja. Es algo primitivo como arma, pero puede romperte la cabeza.\n");
    AddId(({"barra","barra de hierro"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(2);
}
