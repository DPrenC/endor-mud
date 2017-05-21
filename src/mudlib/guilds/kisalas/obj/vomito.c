/****************************************************************************
Fichero: vomito.c
Autor: Kastwey
Fecha: 05/03/2006
Descripción: Un vómito para el gremio de las kisalas... Por si alguien se come el fruto
venenoso ;)
****************************************************************************/


#include <properties.h>

inherit THING;

public int cmd_comer(string str)
{
    if (!str || member(QueryIds(), str) < 0) return 0;
    return notify_fail("Definitivamente, hay gente para todo...\n", NOTIFY_NOT_VALID);
}

create()
{
    ::create();
    SetShort("un vómito");
    SetLong("Es una masa viscosa, informe y de un color rojizo. En ella flotan "
            "grumos de comida a medio digerir.\n");
    SetSmell("Tiene un olor penetrante, casi insoportable.\n");
    SetNoGet(1);
    Set(P_NOSELL,1);
    SetValue(0);
    SetIds(({"vomito","vómito"}));
}

init()
{
    ::init();
    add_action("cmd_comer","comer");
}

