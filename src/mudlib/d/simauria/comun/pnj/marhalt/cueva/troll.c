/****************************************************************************
Fichero: troll.c
Autor: Ratwor
Fecha: 16/08/2007
Descripción: un nuevo troll para la cueva de marhalt.
****************************************************************************/

#include <properties.h>
#include "./path.h"
#include <gremios.h>
#include <races.h>
inherit NPC;

create() {
    ::create();
    SetStandard("un troll", "troll",([ GC_LUCHADOR: 40+d8()]),GENDER_MALE);
    SetShort("un troll de las cavernas");
    SetLong("Es una criatura enorme y verrugosa de piel verde. Sus ojos profundos "
    "miran con desprecio y maldad. Sus enormes garras le bastan para defenderse, "
    "pues su simple presencia es suficiente para intimidar.\n");
    SetGoChance(60);
    AddWalkZones(({MARH("cueva"), CAMINOS "/gremio/"}));
    SetAggressive(1);
    SetSmell("Huele horriblemente mal.\n");
}
