
#include "path.h"
#include <properties.h>

inherit NPC;


void dialogo()
{
    string *mensajes = ({"¿Me has traido mi daga?\n","Espero que tengas "
                         "una buena razón para estar aquí.\n","Si tienes la "
                         "dága, dámela.\n"});
    filter(    all_inventory(environment()),(:(query_once_interactive($1)
           && !QUESTMASTER->QueryQuestSolved("daga_hardester",$1)?
               tell_object($1,"Ardester te dice: " + $2[random(sizeof($2))]):
               0):),mensajes);
}



public create()
{
    ::create();
   SetStandard("Hardester Rankomme","humano",5,GENDER_MALE);
    SetShort("Hardester Rankomme");
    SetLong("Se trata de un humano bien parecido y vestido elegantemente.\n");
    AddId(({"hardester","rankomme","hardester rankomme"}));
    SetAlign(0);
    InitChats (3, ({ SF(dialogo) }) );
}

void has_solved(object pl, object daga)
{
    if (!daga || !pl) return;
    daga->remove();
    if (!present(pl,environment()))
    {
        tell_room(environment(),"Hardester mira hacia todos lados perplejo, "
                                  "como si buscase a alguien, y luego se "
                                  "guarda la daga.\n");
        return;
    }
    /*
    if (QUESTMASTER->QueryQuestSolved("daga_hardester",pl))
    {
        tell_object(pl,"Hardester te dice: Gracias " +
                         capitalize(pl->QueryName()) + ", pero tu ya me "
                         "diste la daga en su momento.\n");
        return;
    }
    */
    QUESTMASTER->SetPlayerQuest("daga_hardester", pl);
    QUESTMASTER->InformSolution("Hardester agradece a " +
                        capitalize(pl->QueryName()) + " que le haya devuelto "
                        "su daga.\n");
    tell_object(pl,"¡¡Parece que has resuelto el Quest!!\nHardester te lo "
                "agradece profundamente pero no suelta el dinero.\n");
    return;
}

public varargs void notify_enter (mixed from, int method, mixed extra)
{
    object obj;
    ::notify_enter (from, method, extra);
    if (!(obj = PO) || !from) return;
    if (!obj->id("hrdaga") || obj->QueryOwner() != from->QueryRealName())
    {
        tell_object(from,"Hardester te da las gracias por el regalo.\n");
        tell_room(environment(),"Hardester le da las gracias a " +
                                  from->QueryName() + " por el regalo.\n",
                                  ({from}));
        return;
    }
    call_out("has_solved",2,from,obj);
    return;
}




