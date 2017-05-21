/*
Archivo: /d/simauria/comun/pnj/cantera/esclavo.c
* Descripción: Aldeano esclavo en la cantera.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit PNJ("sherek/aldea/aldeano");

create()
{
    ::create();
    SetLong(QueryLong()+"Éste está trabajando como esclavo en la cantera, "
        "posiblemente por algún mal comportamiento, o tal vez sólo por el "
        "capricho de algún guardián.\n");
    AddItem(QUEST+"sherek/pico",REFRESH_REMOVE,1,SF(wieldme));
    SetGoChance(90);
    AddWalkZones(SHERCAN("alto"));
    InitChats(10,({"El aldeano gime: Yo no hice nada, te lo juro.\n",
        "El aldeano suspira: ¡Qué lento pasa el tiempo aquí!\n",
        "El aldeano pica la roca con desgana.\n",
        "El aldeano solloza: ¿Qué pensarán mis niños? ¡Su padre esclavo!\n"}));
    InitAChats(10,"El aldeano ruge: ¡Soy esclavo, pero no estoy dispuesto a "
        "morir aquí!\n");
}
