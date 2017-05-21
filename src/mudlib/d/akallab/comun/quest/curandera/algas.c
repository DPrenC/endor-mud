/*
DESCRIPCION    : un punyado de algas para el quest de la curandera
FICHERO        : /d/akallab/comun/quest/curandera/algas.c
MODIFICACION   : 01-03-99 [Angor@Simauria].
*/

#include "path.h"
#include AK_MACRO

#include <herbs.h>

inherit HERB;

create()
{
    ::create();
    SetShort("un pu�ado de algas");
    SetLong("Es un h�medo y viscoso pu�ado de algas, de un color verde bastante oscuro. "
        "Desprenden un fuerte olor.\n");
    AddId(({"algas","alga","punyado de algas","pu�ado de algas","cur_quest_12"}));
    SetSmell("Las algas desprenden un fuerte olor.\n");
    SetWeight(100);
    SetClass(HERB_CLASS_FOOD);
    SetPower(25+random(10));
    SetValue(QueryPowerNumber());
}
