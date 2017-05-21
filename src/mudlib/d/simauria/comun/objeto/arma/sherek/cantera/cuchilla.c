/****************************************************************************
Fichero: /d/simauria/comun/objeto/arma/sherek/cantera/cuchilla.c
Autor: Yalin
Fecha: 17/04/2008 13:38
Descripción: cuchilla que llevan los demonios.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_ESPADA,8,P_SIZE_GENERIC,M_ACERO);
    SetShort("una enorme cuchilla");
    SetLong("Es una vieja cuchilla, grande y horrorosa, encontrada los dioses sabrán dónde. "
        "Sólo verla te pone los pelos de punta, no quieres ni imaginar cómo será sentirla.\n");
    AddId(({"cuchilla","cuchilla enorme","enorme cuchilla"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(2);
}
