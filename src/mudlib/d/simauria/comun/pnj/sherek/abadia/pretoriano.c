/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/abadia/pretoriano.c
Autor: Lug y Yalin
Fecha: 25/05/2007
Descripción: Superguardián para los terrenos de la abadía.
****************************************************************************/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <skills.h>
inherit PNJ("sherek/gbase");

create()
{
    ::create();
    SetStandard("un pretoriano","humano",([ GC_LUCHADOR:60+d8() ]),GENERO_MASCULINO);
    SetName("un pretoriano");
    SetShort("un guardia pretoriano");
    SetLong("Es un miembro del cuerpo especial, de la élite de los "
        "guardianes dedicados al servicio de seguridad en los dominios de "
        "Sherek.\nEste cuerpo está destinado al servicio privado de la "
        "abadía y sus terrenos adyacentes.\nEs un luchador fornido y "
        "altamente cualificado para la lucha cuerpo a cuerpo, con o sin armas. "
        "Si piensas entrar en estos dominios, será mejor que cuentes con él "
        "antes de intentar nada.\n");
    AddId(({"pretoriano","guardia pretoriano","guardian pretoriano","guardián pretoriano"}));
    SetAggressive(1);
    SetCon(QueryCon()+5);
    SetHP(QueryMaxHP());
    SetStr(QueryStr()+2);
    SetGoChance(90);
    Set(P_CANT_LURE,1);
    AddItem(ARMA("sherek/aldea/espada2"),REFRESH_REMOVE,2,SF(wieldme));
    AddItem(PROT("sherek/aldea/coraza"),REFRESH_REMOVE,1,SF(wearme));
    InitAChats(10,"El pretoriano ruge: ¡El colmo del atrevimiento! ¡¿Habráse "
        "visto tamaña desvergüenza?!\n");
}

init()
{
    ::init();
    write("Un pretoriano grita: ¿Pero qué es esto? ¿Cómo demonios has "
        "llegado hasta aquí?\n");
}
