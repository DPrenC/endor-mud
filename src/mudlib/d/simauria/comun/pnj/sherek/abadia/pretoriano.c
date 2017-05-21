/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/abadia/pretoriano.c
Autor: Lug y Yalin
Fecha: 25/05/2007
Descripci�n: Superguardi�n para los terrenos de la abad�a.
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
    SetLong("Es un miembro del cuerpo especial, de la �lite de los "
        "guardianes dedicados al servicio de seguridad en los dominios de "
        "Sherek.\nEste cuerpo est� destinado al servicio privado de la "
        "abad�a y sus terrenos adyacentes.\nEs un luchador fornido y "
        "altamente cualificado para la lucha cuerpo a cuerpo, con o sin armas. "
        "Si piensas entrar en estos dominios, ser� mejor que cuentes con �l "
        "antes de intentar nada.\n");
    AddId(({"pretoriano","guardia pretoriano","guardian pretoriano","guardi�n pretoriano"}));
    SetAggressive(1);
    SetCon(QueryCon()+5);
    SetHP(QueryMaxHP());
    SetStr(QueryStr()+2);
    SetGoChance(90);
    Set(P_CANT_LURE,1);
    AddItem(ARMA("sherek/aldea/espada2"),REFRESH_REMOVE,2,SF(wieldme));
    AddItem(PROT("sherek/aldea/coraza"),REFRESH_REMOVE,1,SF(wearme));
    InitAChats(10,"El pretoriano ruge: �El colmo del atrevimiento! ��Habr�se "
        "visto tama�a desverg�enza?!\n");
}

init()
{
    ::init();
    write("Un pretoriano grita: �Pero qu� es esto? �C�mo demonios has "
        "llegado hasta aqu�?\n");
}
