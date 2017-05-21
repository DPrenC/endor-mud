/* Archivo: /d/simauria/comun/pnj/abadia/guardian.c
* Descripción: Guardián de la abadía para lavigilancia de la aldea y sus aledaños.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <skills.h>
inherit PNJ("sherek/gbase");

public void encuentro()
{
    foreach(object inv:all_inventory(environment()))
    {
        if (query_once_interactive(inv))
        {
            tell_object(inv,("El guardia te azota con su látigo, mientras te "
                "grita:\n ¡eh, tú! Aquí se viene a trabajar, no a estar "
                "paseando al aire'.\n"));
            inv->AddHP(-d4());
            object ob = present("PicoQuest",inv);
            if (!ob)
            {
                ob = clone_object(QUEST+"sherek/pico");
                ob->move(inv);
                tell_object(inv,("El guardia te observa un momento y dice: Vaya, "
                    "has perdido tu pico, ¡eh? Bueno, por aquí habrá alguno.'\n"
                    "El guardia rebusca entre las rocas, encuentra un pico y "
                    "te lo entrega.\n"));
                say("El guardia mira a "+CAP(inv->QueryName())+" y le dice: "
                    "Vaya, has perdido tu pico, ¿eh? Bueno, por aquí habrá "
                    "alguno.'\nEl guardia rebusca entre las rocas, encuentra un "
                    "pico, y se lo entrega a "+CAP(inv->QueryName())+".\n",inv);
            }
        }
    }
}

create()
{
    ::create();
    SetStandard("un guardián","humano",([ GC_LUCHADOR:40+d10() ]), GENERO_MASCULINO);
    SetShort("un guardián");
    SetLong("Es un miembro del servicio privado de guardias de la abadía de "
        "Sherek.\nÉste es uno de los que tiene hoy el turno de vigilancia y "
        "control de esclavos en la cantera.\n");
    SetCon(QueryCon()+5);
    SetHP(QueryMaxHP());
    SetGoChance(90);
    AddWalkZones(SHERCAN("alto"));
    AddItem(ARMA("sherek/aldea/espada"),REFRESH_REMOVE,1,SF(wieldme));
    AddItem("/obj/armas/latigo",REFRESH_REMOVE,1,SF(wieldme));
    AddItem(PROT("sherek/aldea/coraza"),REFRESH_REMOVE,1,SF(wearme));
    InitChats(10,({"El Guardián te mira con suspicacia.\n",
        "El guardián refunfuña algo sobre la hora de su relevo.\n",
        "El guardián grita: ¡A trabajar! ¡No quiero ver a nadie parado!\n",
        "El guardián acaricia la empuñadura de su espada.\n",
        "El guardián dice: No se te ocurra ninguna tontería.\n"}));
    InitAChats(10,({"El guardián grita: ¡Eso ha sido una estupidez!\n"}));
}

init()
{
    ::init();
    call_out("encuentro",1);
}
