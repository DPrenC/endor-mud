/****************************************************************************
Fichero: /d/simauria/comun/pnj/abadia/monjebase.c
Autor: Lug y Yalin
Fecha: 02/09/2006
Descripción: Base para los clérigos de la abadía.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
#include <moving.h>
#include <spellmonster.h>
#include <skills.h>
inherit SPELLMONSTER;

//variables
static string pSpellName;
int danyo;

//funciones
public status check_sp();
public string SetSpellName(string conj);
public string QuerySpellName();
public int magia();
void aviso();

create()
{
    ::create();
    SetIds(({"monje","humano","clérigo","clerigo"}));
    SetWhimpy(-1);
    SetSpellChance(1000);
    Set(P_NOGET, 0);
    AddSpell("conjuros",
        ([
            S_CHECKFUN: SF(check_sp),
            S_FUN: SF(magia),
            S_SP:2,
            S_CHANCE: 1000,
            S_VICTIMS: 1,
        ]));
    SetCitizenship("sherek");
}

//magia
public status check_sp() { return QuerySP() > 0; }
public string SetSpellName(string conj) { return pSpellName = conj; }
public string QuerySpellName() { return pSpellName; }

public int magia()
{
    danyo = (QueryLevel()+QueryInt())/5;
    object *adversarios, enemigo;
    adversarios = QueryEnemies() || ({});
    if(!sizeof(adversarios)) return 0;
    enemigo = adversarios[random(sizeof(adversarios))];
    switch (d4())
    {
        case 1:
            if (QuerySP() <20) break;
            AddSP(-20);
            tell_object(enemigo,capitalize(QueryName())+" invoca a Sherek "
                "contra tu alma.\nSientes que el poder de la diosa te daña.\n");
            say(capitalize(QueryName())+" invoca a Sherek "
                "contra el alma de "+capitalize(enemigo->QueryName())+", y ves "
                "cómo el poder de la diosa le daña.\n",enemigo);
            SetSpellName("Herida Leve");
            enemigo->Defend(danyo, DT_ZAP, DEFEND_SPELL);
            SetSpellName(0);
        break;
        case 2:
            if (QuerySP() <40) break;
            AddSP(-40);
            tell_object(enemigo,capitalize(QueryName())+" invoca a Sherek "
                "contra tu alma.\nSientes que el poder de la diosa te hiere duramente.\n");
            say(capitalize(QueryName())+" invoca a Sherek "
                "contra el alma de "+capitalize(enemigo->QueryName())+", y ves "
                "cómo el poder de la diosa le hiere duramente.\n",enemigo);
            SetSpellName("Herida Menor");
            enemigo->Defend(danyo*2, DT_ZAP, DEFEND_SPELL);
            SetSpellName(0);
        break;
        case 3:
            if (QuerySP() <60) break;
            AddSP(-60);
            tell_object(enemigo,capitalize(QueryName())+" invoca a Sherek "
                "contra tu alma.\nSientes que el poder de la diosa te hiere gravemente.\n");
            say(capitalize(QueryName())+" invoca a Sherek "
                "contra el alma de "+capitalize(enemigo->QueryName())+", y ves "
                "cómo el poder de la diosa le hiere gravemente.\n",enemigo);
            SetSpellName("Herida Mayor");
            enemigo->Defend(danyo*3, DT_ZAP, DEFEND_SPELL);
            SetSpellName(0);
        break;
        case 4:
            if (QuerySP() <80) break;
            AddSP(-80);
            tell_object(enemigo,capitalize(QueryName())+" invoca a Sherek "
                "contra tu alma.\nSientes que el poder de la diosa te hiere muy gravemente.\n");
            say(capitalize(QueryName())+" invoca a Sherek "
                "contra el alma de "+capitalize(enemigo->QueryName())+", y ves "
                "cómo el poder de la diosa le hiere muy gravemente.\n",enemigo);
            SetSpellName("Herida Crítica");
            enemigo->Defend(danyo*4, DT_ZAP, DEFEND_SPELL);
            SetSpellName(0);
        break;
    }
    return 1;
}

// no se le paraliza
void aviso()
{
    write(capitalize(QueryName())+" ve tu pobre intento de detenerle, y se ríe en tu cara.\n");
    say(capitalize(QueryName())+" ve el pobre intento de "+capitalize(TP->QueryName())+
        " de detenerle, y se ríe en su cara",TP);
}

mixed SetCombatDelay(int time, string s)
{
    call_out("aviso", 0);
    return 1;
}

// respuesta no standard a coger
public varargs int move(mixed dest, int method, mixed extra)
{
    object pl = PO;
    if (method == M_GET && pl && query_once_interactive(pl))
    {
        write(CAP(QueryName())+" te gruñe: Aparta tus manos de mí, sacríleg"+(TP->QueryGenderEndString())+"!\n");
        return ME_NO_GET;
        }
    return ::move(dest, method, extra);
}

public varargs void Die(mixed silent)
{
    danyo = QueryLevel()+QueryInt();
    if (QueryKiller())
    {
    	tell_object(QueryKiller(),capitalize(QueryName()) + ", con su "
    	    "último aliento, pide tu muerte a Sherek, y sientes que el poder "
    	    "de la diosa te hiere con extrema crueldad.\n");
        say(capitalize(QueryName()) + ", aprovechando las pocas fuerzas "
            "que le quedan, pide a Sherek la muerte de "+ capitalize(QueryKiller()->QueryName()) +
            ", y ves cómo el poder de la diosa le hiere con extrema "
            "crueldad.\n",QueryKiller());
        SetSpellName("Herida Mortal");
        QueryKiller()->Defend(danyo, DT_ZAP, DEFEND_SPELL);
        SetSpellName(0);
    }
    ::Die(silent);
}
