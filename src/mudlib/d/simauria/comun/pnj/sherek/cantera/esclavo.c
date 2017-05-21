/*
Archivo: /d/simauria/comun/pnj/cantera/esclavo.c
* Descripci�n: Aldeano esclavo en la cantera.
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
    SetLong(QueryLong()+"�ste est� trabajando como esclavo en la cantera, "
        "posiblemente por alg�n mal comportamiento, o tal vez s�lo por el "
        "capricho de alg�n guardi�n.\n");
    AddItem(QUEST+"sherek/pico",REFRESH_REMOVE,1,SF(wieldme));
    SetGoChance(90);
    AddWalkZones(SHERCAN("alto"));
    InitChats(10,({"El aldeano gime: Yo no hice nada, te lo juro.\n",
        "El aldeano suspira: �Qu� lento pasa el tiempo aqu�!\n",
        "El aldeano pica la roca con desgana.\n",
        "El aldeano solloza: �Qu� pensar�n mis ni�os? �Su padre esclavo!\n"}));
    InitAChats(10,"El aldeano ruge: �Soy esclavo, pero no estoy dispuesto a "
        "morir aqu�!\n");
}
