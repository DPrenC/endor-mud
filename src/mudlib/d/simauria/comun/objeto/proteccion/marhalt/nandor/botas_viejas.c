/****************************************************************************
Fichero: botas_viejas.c
Autor: Ratwor
Fecha: 28/11/2007
Descripción: parte del equipo de los guardias del castillo.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_LARGE, M_CUERO);
    SetShort("unas viejas botas");
    SetLong("Son un par de viejas botas de color indefinido que llegan a media "
    "pantorrilla. Están llenas de arañazos y parches mal ajustados, mientras que la "
    "punta rasgada deja sobresalir los dedos del pie.\n");
    AddId(({"viejas botas", "botas", "viejas", "botas viejas"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL);
    SetWeight(1200);

}
