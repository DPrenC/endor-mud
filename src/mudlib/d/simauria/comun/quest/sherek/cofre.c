#include "path.h"
#include <properties.h>
#include <messages.h>
#include <moving.h>
#include <lock.h>
#include <search.h>
inherit "/std/room/items";
inherit "/obj/chest";

int nopuedes(string str)
{
    if (TO->id(str)) return notify_fail("Hum... Mala idea. El propietario "
        "podría venir alertado por el ruido, y tendrías problemas.\n",
        NOTIFY_NOT_VALID);
    return 0;
}

int abrir_(string str)
{
    if (!TO->id(str)) return 0;
        object llave=present("quest_llave_cofre",TP);
    int sabe=TP->QueryAttribute("sabelibro");
    int tiene=TP->QueryAttribute("tienellave");
    if ((QUESTMASTER->QueryQuestSolved("DarylQuest",TP)) || (!llave))
    {
        tell_object(TP,("el cofre está cerrado con llave.\n"));
        say(W(CAP(TP->QueryName())+" intenta abrir el cofre, pero no tiene la llave.\n"),TP);
        return 1;
    }
    if (!tiene)
    {
        tell_object(TP,("Cuando estás abriendo el cofre, aparece Marath, que "
            "al ver lo que haces, te agarra por el cuello y te dice: "
            "'¿Pretendías robarme? ¿Quién te ha dicho que lo tenía aquí?\n"
            "Acto seguido, te obsequia con una cuchillada mortal, te quita "
            "la llave, te saca de la tumba por los pelos y se marcha, sin "
            "preocuparse lo más mínimo de ti.\n"));
        say(W(CAP(TP->QueryName())+" intenta abrir el cofre.\nEn ese momento, "
            "aparece Marath, quien al ver la situación le dice: '¿Pretendías "
            "robarme? ¿Quién te ha dicho que lo tenía aquí?'\nActo seguido, "
            "le coge del cuello, le quita la llave, le da una horrible "
            "cuchillada, le saca de la tumba y le abandona en el cementerio.\n"),TP);
        llave->remove();
        if (llave) destruct(llave);
        TP->SetHP(4);
        TP->SetSP(4);
        TP->SetDrink(1);
        TP->SetFood(1);
        TP->move(SHERALD("cementerio/cementerio01"),M_SILENT);
        TP->LookAfterMove();
        return 1;
    }
    if (sabe)
    {
        object ob, ob1;
        int mit;
        mit = 10+random(10);
        ob=clone_object("/obj/money");
        ob->SetMoney((["mithril":mit]));
        ob->move(TP);
        ob1=clone_object(QUEST+"sherek/libro");
        ob1->SetOwner(TP->QueryRealName());
        TP->SetAttribute("tienelibro",time());
        llave->remove();
        if (llave) destruct(llave);
        TP->RemoveAttribute("sabellave");
        TP->RemoveAttribute("tienellave");
        TP->RemoveAttribute("sabecofre");
        TP->SetAttribute("hechoninyo",time());
        tell_object(TP,("Abres el cofre, y en su interior descubres un libro "
            "y algo de dinero, que naturalmente "));
        if (ob1->move(TP)) write("te quedas, faltaría más.\n");
        else
        {
            write("intentas coger, pero ya no puedes con más cosas y se te cae "
                "al suelo.\n");
            ob1->move(environment());
        }
        return 1;
    }
    return 0;
}

create()
{
    ::create();
    SetIds(({"cofre"}));
    SetShort("Un cofre");
    SetLong("Es un pesado baúl de madera de roble.\n");
    AddId(({"cofre","baul","baúl"}));
    SetPreContent("Dentro puedes ver:\n");
    SetNoGet("No puedes con él.\n");
    SetMaxIntWeight(20000);
}

init()
{
    ::init();
    if ((!TP->QueryAttribute("sabecofre")) && (!TP->QueryAttribute("tienelibro")) && (!QUESTMASTER->QueryQuestSolved("DarylQuest",TP))) TP->SetAttribute("sabecofre",time());
    add_action("nopuedes","romper");
    add_action("nopuedes","golpear");
    add_action("nopuedes","forzar");
    add_action("nopuedes","reventar");
    add_action("abrir_","abrir");
}
