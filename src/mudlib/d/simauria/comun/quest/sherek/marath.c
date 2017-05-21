/* Archivo: /d/simauria/comun/pnj/abadia/marath.c
* Descripci�n: Marath el asesino, taberna.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <guild.h>
#include <combat.h>
#include <properties.h>
#include <skills.h>
inherit PNJ("sherek/aldea/base");


string dialogo()
{
    switch (d3())
    {
        case 1:
            return "Marath grita: �A ver si te das m�s prisa! �Crees que no "
                "tengo nada mejor que hacer?\n";
        break;
        case 2:
            return "Marath grita: �eh, viejo! �y mi comida?\n";
        break;
        case 3:
            foreach(object ob:all_inventory(environment()))
            {
                if (query_once_interactive(ob) && !ob->QueryInvis())
                {
                    if (QUESTMASTER->QueryQuestSolved("DarylQuest",ob))
                    {
                        tell_object(ob,"Marath te apunta con el dedo y te dice: "
                            "Tranquil"+(ob->QueryGenderEndString())+", "+CAP(ob->QueryName())+". No te guardo "
                            "rencor. �Sabes? Despu�s de todo, me vino bien. "
                            "Ahora soy un ciudadano que se gana la vida honradamente.\n");
                        return "";
                    }
                    if (ob->QueryAttribute("tienelibro"))
                    {
                        tell_object(ob,"Marath gimotea nervioso: �Me han robado! "
                            "�Lo han encontrado! �C�mo me habr� despistado as�?\n");
                        return "";
                    }
                    if (ob->QueryAttribute("sabecofre"))
                    {
                        tell_object(ob,"Marath murmura: Alguien ha estado all� "
                            "abajo. He visto huellas por todo al rededor.\n");
                        return "";
                    }
                    switch (d4())
                    {
                        case 1:
                            tell_object(ob,"Marath mira disimuladamente a todos lados.\n");
                            return "";
                        break;
                        case 2:
                            tell_object(ob,"Marath murmura: �ste es un buen "
                                "escondrijo. Nadie me buscar� en este villorrio.\n");
                        break;
                        case 3:
                            tell_object(ob,"Marath murmura: hmmm, nadie sospecha "
                                "lo del bot�n. No quisiera que empezaran a "
                                "buscarlo.\n");
                        break;
                        case 4:
                            tell_object(ob,"Marath murmura: Aqu� no me encontrar�n. "
                                "En unos meses se habr�n olvidado.\n");
                        break;
                    }
                }
            }
            break;
    }
    return "";
}

create()
{
    ::create();
    SetStandard("Marath","humano",([ GC_ASESINOS: 50 ]), GENERO_MASCULINO);
    SetName("Marath");
    SetShort("Marath, el asesino");
    SetLong("Marhat es un humano alto y atl�tico.\nTiene ojos penetrantes, y "
        "cara de pocos amigos.\nCorren rumores de que vino aqu� huyendo desde "
        "alg�n lugar del oeste, por alg�n crimen que cometi� en alguna lejana "
        "ciudad de Simauria.\n");
    AddId(({"marath","asesino","humano"}));
    SetHP(QueryMaxHP());
    SetAlign(-200);
    AddItem("/guilds/asesinos/obj/black_katana", REFRESH_REMOVE,1, SF(wieldme));
    InitChats(10,SF(dialogo));
    InitAChats(10,({"Marath ruge: �Pero c�mo te atreves, insolente? �No "
        "sabes con qui�n te has metido!\n"}));
}
