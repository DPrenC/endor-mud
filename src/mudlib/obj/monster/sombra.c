/**
 * simauria /obj/monster/sombra
 * la sombra para las kisalas
**/

#include <sounds.h>

inherit NPC;

private static object pOwner;

public object SetOwner(object ob)
{
    if (!ob) return pOwner = 0;
    SetStandard(ob->QueryName(), ob->QueryRace(), ([ob->QueryGuild() : ob->QueryGuildLevel()]), ob->QueryGender());
    SetShort(ob->QueryPresay() + ob->QueryShort() + " " + ob->QueryTitle());
    SetLong(ob->QueryLong());
    SetCon(ob->QueryCon());
    SetDex(ob->QueryDex());
    SetInt(ob->QueryInt());
    SetStr(ob->QueryStr());
    SetNoGet(1);
    SetWeight(ob->QueryWeight());
    AddId("sombra_" + NREAL(ob));
    ob->AddFollower(TO);
    call_out("MeVoy", 180);

    return pOwner = ob;
}
public object QueryOwner() { return pOwner; }


public int QueryIsSombra() { return 1; }

private int me_atacan(object ob)
{
    if (pOwner)
    {
        if (pOwner == ob)
        {
            notify_fail( "Al atacar a tu sombra, esta se desvanece.\n");
            play_sound(environment(), SND_MAGIA("desvanecer_sombra"));
            tell_room(environment(), CAP(QueryName()) + " se desvanece.\n", ({pOwner}));
            return remove(), 0;
        }
        pOwner->AddEnemy(ob);
    }
    return notify_fail("Intentas atacar a " + CAP(QueryName()) + ", pero "
                       "al instante desaparece, reapareciendo a varios metros de ti.\n",
                       NOTIFY_NOT_VALID);
}


create()
{
    ::create();
    SetChkFightFunction(SF(me_atacan));
    SetChkMagicFunction(SF(me_atacan));
}
public void MeVoy()
{
    if (environment())
    {
        if (pOwner)
        {
            tell_room(environment(),CAP(QueryName()) + " se desvanece.\n", ({pOwner}));
            tell_object(pOwner, "La ilusión de tu sombra se desvanece.\n");
        }
        else tell_room(environment(),CAP(QueryName()) + " se desvanece.\n");
    }
    play_sound(environment(), SND_MAGIA("desvanecer_sombra"));
    remove();
}

heart_beat()
{
    ::heart_beat();
    if (!pOwner) MeVoy();
}

public void notify_enter(mixed from, int method, mixed extra)
{
    object cosa = PO;
    if (!cosa) return;
    call_out("MeTraspasa", 0, cosa);
}

public void MeTraspasa(object cosa)
{
    object env = environment();
    if (!env) return;
    tell_room(env, CAP(cosa->QueryShort()) + " traspasa a " + CAP(QueryName()) + " y cae al suelo.\n");
    cosa->move(env);
}
