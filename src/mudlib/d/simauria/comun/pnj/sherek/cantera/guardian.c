/* Archivo: /d/simauria/comun/pnj/abadia/guardian.c
* Descripci�n: Guardi�n de la abad�a para lavigilancia de la aldea y sus aleda�os.
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
            tell_object(inv,("El guardia te azota con su l�tigo, mientras te "
                "grita:\n �eh, t�! Aqu� se viene a trabajar, no a estar "
                "paseando al aire'.\n"));
            inv->AddHP(-d4());
            object ob = present("PicoQuest",inv);
            if (!ob)
            {
                ob = clone_object(QUEST+"sherek/pico");
                ob->move(inv);
                tell_object(inv,("El guardia te observa un momento y dice: Vaya, "
                    "has perdido tu pico, �eh? Bueno, por aqu� habr� alguno.'\n"
                    "El guardia rebusca entre las rocas, encuentra un pico y "
                    "te lo entrega.\n"));
                say("El guardia mira a "+CAP(inv->QueryName())+" y le dice: "
                    "Vaya, has perdido tu pico, �eh? Bueno, por aqu� habr� "
                    "alguno.'\nEl guardia rebusca entre las rocas, encuentra un "
                    "pico, y se lo entrega a "+CAP(inv->QueryName())+".\n",inv);
            }
        }
    }
}

create()
{
    ::create();
    SetStandard("un guardi�n","humano",([ GC_LUCHADOR:40+d10() ]), GENERO_MASCULINO);
    SetShort("un guardi�n");
    SetLong("Es un miembro del servicio privado de guardias de la abad�a de "
        "Sherek.\n�ste es uno de los que tiene hoy el turno de vigilancia y "
        "control de esclavos en la cantera.\n");
    SetCon(QueryCon()+5);
    SetHP(QueryMaxHP());
    SetGoChance(90);
    AddWalkZones(SHERCAN("alto"));
    AddItem(ARMA("sherek/aldea/espada"),REFRESH_REMOVE,1,SF(wieldme));
    AddItem("/obj/armas/latigo",REFRESH_REMOVE,1,SF(wieldme));
    AddItem(PROT("sherek/aldea/coraza"),REFRESH_REMOVE,1,SF(wearme));
    InitChats(10,({"El Guardi�n te mira con suspicacia.\n",
        "El guardi�n refunfu�a algo sobre la hora de su relevo.\n",
        "El guardi�n grita: �A trabajar! �No quiero ver a nadie parado!\n",
        "El guardi�n acaricia la empu�adura de su espada.\n",
        "El guardi�n dice: No se te ocurra ninguna tonter�a.\n"}));
    InitAChats(10,({"El guardi�n grita: �Eso ha sido una estupidez!\n"}));
}

init()
{
    ::init();
    call_out("encuentro",1);
}
