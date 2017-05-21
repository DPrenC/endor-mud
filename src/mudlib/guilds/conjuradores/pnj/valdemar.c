#include <wizlevels.h>
#include <spellmonster.h>
#include <properties.h>
#include <gremios.h>
#include <money.h>
#include <messages.h>


#define MSG_A_JUG tell_room(environment(), ({MSG_SEE, "Valdemar le dice algo a " +\
CAP(NNAME(jug)) + ".\n", ({MSG_HEAR, "Alguien dice algo.\n"})}),\
({jug}));
#define COSTE (10 * MONEY_DEMON->QueryCoinValue("mithril"))


inherit "/obj/monster/spellmonster";


create()
{
    ::create();
    SetStandard("Valdemar","humano",90,GENDER_MALE);
    SetShort("Valdemar, el maestro conjurador");
    SetLong("Ves a un viejo humano con la mirada muy seria. Una coleta recoge "
            "su largo pelo blanco y la barba, también blanca, le llega hasta la boca del estómago.\n");
    SetAC(5);
    InitChats(4,({"Valdemar te mira profundamente.\n",
                  "Valdemar dice: Nosotros, los conjuradores, no tememos a nada ni a nadie.\n",
                  "Valdemar dice: Por apenas 10 monedas de mithril puedo enseñarte "
                  "perfectamente el conjuro que desees, solo tienes que usar la palabra "
                "aprender, seguida del conjuro que quieras que te ayude a perfeccionar.\n"}));
}

public int cmd_aprender(string conjuro)
{
    int dinero;
    object jug;
    mapping sp;
    mixed result;


    if (!(jug = TP) || !query_once_interactive(jug)) return 0;

    if (jug->QueryGuild()!=GC_CONJURADORES)
    {
        MSG_A_JUG;
        return notify_fail("Valdemar te dice: Lo siento, solo enseño a los de mi gremio.\n");
    }

    if (jug->QueryGuildLevel()<40)
    {
        MSG_A_JUG;
        return notify_fail("Valdemar te dice: Solo enseño a conjuradores de más de nivel 40.\n");
    }

    if (!conjuro)
    {
        return notify_fail("Valdemar te dice: Debes decirme el nombre del conjuro que "
                           "deseas que te enseñe.\n");
        MSG_A_JUG;
        }

    conjuro=lower_case(conjuro);
    if (!jug->HasSpell(conjuro))
    {
        MSG_A_JUG;
        return notify_fail("Valdemar te dice: No conoces ese conjuro. Sólo puedo "
                           "ayudarte a perfeccionar los conjuros que ya has aprendido.\n");
    }

    sp= jug->QuerySpells();
    if (sp[conjuro,1]>70)
    {
        MSG_A_JUG;
        return notify_fail("Valdemar te dice: No puedo enseñarte mejor ese conjuro.\n");
    }

    dinero = MONEY_LIB->QuerySomeonesValue(TP);
    if (dinero< COSTE)
    {
        MSG_A_JUG;
        return notify_fail("Valdemar te dice: Lo siento, cobro " +
                           MONEY_LIB->Value2String(COSTE) + ".\n");
    }

    if (jug->AddPlayerSpell(conjuro,1,100,0)<1)
    {
        MSG_A_JUG;
        return notify_fail("Valdemar te dice: No puedo enseñarte mejor ese conjuro.\n");
    }
    result = MONEY_LIB->PayValueString2(jug,COSTE, 0, "por aprender mejor el conjuro " + conjuro);
    if (!pointerp(result))
    {
        MSG_A_JUG;
        return notify_fail("Valdemar te dice: Lo siento, no puedes pagarme lo que pido por "
                           "enseñarte el conjuro.\n");
    }
    tell_object(jug, result[0] + "Valdemar te enseña mejor el conjuro.\n");
    tell_room(environment(), ({MSG_SEE, result[1]}), ({jug}));
    return 1;
}





init()
{
    ::init();
    add_action("cmd_aprender", "aprender");
}




public varargs void Die(mixed silent)
{
    SetHP(10); // Es imposible que muera :)))
}
