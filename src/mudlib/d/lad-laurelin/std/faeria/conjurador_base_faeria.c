/***
fichero: conjurador_base_faeria.c
Autor: kastwey@simauria
Descripción: Conjurador base.
Creación: 26/12/2004
***/
#include "path.h"
#include <spellmonster.h>
#include <colours.h>
#include <guild.h>
#include <combat.h>
#include <moving.h>

#define SEXO (enemigo->QueryGender() == 2?"a":"o")

inherit STD_FAERIA("pnj_spell_base_faeria");

void aviso();

public status check_sp();
public int magia();
object enemigo;

create()
{
    ::create();
   AddId("conjurador");
    SetCastChance(30+random(11));
    AddSpell("conjuros",
        ([
            S_CHECKFUN: SF(check_sp),
            S_FUN: SF(magia), S_SP:2,
            S_CHANCE: 80,
            S_VICTIMS: 1,
        ]));
}

void aviso()
{
    write(W(capitalize(QueryName()) + " sonríe maliciosamente dándote a entender que tu intento de inmovilizarle fue inhutil.\n"));
    say(W(capitalize(QueryName()) + " sonríe maliciosamente a " + capitalize(TP->QueryName()) + ", dándole a entender que su intento de inmovilizarlo fue inhutil.\n"), TP);
}

mixed SetCombatDelay(int time , string s)
{
    call_out("aviso", 1);
    return 1;
}

public status check_sp()
{
    return QuerySP()>0;
}


public int magia()
{
    int pv, i;
    object *adversarios, bicho;
    bicho=TO;
    adversarios = QueryEnemies();
    if(!sizeof(adversarios)) return 0;
    enemigo=adversarios[random(sizeof(adversarios))];
    switch (random(100))
    // todos los conjuros que lanza.
    {
        case 0 .. 19:/*bola de fuego*/ //de 1 a 20 en masa
            if (!TO->QuerySP() >= 20)
            break;
            TO->AddSP(-20);
            pv=random(20)+1;
            tell_room(environment(TO), W(TC_RED+capitalize(QueryName()) + " hace un gesto con sus manos mientras pronuncia unas extrañas palabras: ¡Creil Ignem Spzereph!!!\n"
            "Al instante, aparece entre sus manos una gran bola de fuego "
            "que impulsa hacia delante impactando sobre todos sus adversarios.\n"+TC_NORMAL));
            SetSpellName("bola de fuego");
            call_other(adversarios, "Defend", pv, DT_FIRE, DEFEND_SPELL);
            SetSpellName(0);
            break;
        case 20 .. 39: // lanza de ácido
            if (!TO->QuerySP() >= 10)
            break;
            TO->AddSP(-10);
            pv=random(QueryLevel() / 2)+1;
            tell_room(environment(TO), W(capitalize(QueryName()) + " extiende un brazo y lo eleva por encima de su cabeza.\n"
                "Al instante, en su mano aparece una lanza de ácido que instantáneamente lanza contra " + capitalize(enemigo->QueryName()) + ".\n"), ({enemigo}));
            tell_object(enemigo, W(capitalize(QueryName()) + " eleva un brazo por encima de su cabeza.\n"
                "Al instante, en su mano aparece una lanza de ácido que te arroja.\n"));
            SetSpellName("lanza de ácido");
            enemigo->Defend(pv, DT_ACID, DEFEND_SPELL);
            SetSpellName(0);
            break;
        case 40 ..49:/*elemental*/ //el típico elemental de fuego mayor
            if (!TO->QuerySP() >= 100) break;
            TO->AddSP(-100);
            bicho = clone_object(PNJ_PUESTO("elemental_mayor"));
            if (bicho->move(environment())==ME_OK)
            {
                for (i=sizeof(adversarios);i--;) bicho->AddEnemy(adversarios[i]);
                tell_room(environment(), W(TC_YELLOW+capitalize(QueryName()) + " comienza a girar"
                    " sobre sí mismo. De repente se para en seco y alza las "
                    "manos hacia el cielo. Un elemental de fuego mayor"
                    " aparece a su lado.\n"+TC_NORMAL));
            }
            bicho = TO;
            break;
        case 50 .. 69:
            // meteorito.
            if (!TO->QuerySP() >= 20) break;
            tell_room(environment(TO), W(capitalize(QueryName()) + " cierra los ojos y se concentra.\n"
                "Al instante, crea una tromba de meteoritos que impactan en " + capitalize(enemigo->QueryName()) + ".\n"), ({enemigo}));
            tell_object(enemigo, W(capitalize(QueryName()) + " cierra los ojos y se concentra.\n"
                "Al instante, crea una tromba de meteoritos que impactan sobre ti.\n"));
            SetSpellName("meteorito");
            enemigo->Defend(40+random(20), DT_PIERCE, DEFEND_SPELL);
            SetSpellName(0);
            TO->AddSP(-40);
            break;
        case 70 .. 99: // frío intenso
            if (TO->QueryHP()<15) break;
            tell_room(environment(),W(capitalize(QueryName()) + " levanta las manos y se concentra mirando a " + enemigo->QueryName() + ". Un frío intenso se apodera de " + enemigo->QueryName() + " y ves como comienza a congelarse.\n"),({enemigo}));
            tell_object(enemigo,W(capitalize(QueryName()) + " se concentra y notas como todos tus miembros se congelan rápidamente.\n"));
            enemigo->SetCombatDelay(3+random(10),"Estás congelado.\n");
            break;
    }
    return 1;
}



public varargs void Die(mixed silent)
{
    if (QueryKiller())
    {
    	tell_object(QueryKiller(), W(capitalize(QueryName()) + " da un grito sobrehumano y con las pocas fuerzas que le quedan, alza las manos y te lanza un poderoso rayo que te impacta de lleno.\n"));
        say(W(capitalize(QueryName()) + ", aprovechando las pocas fuerzas que le quedan, alza las manos y envía un poderoso rayo a " + capitalize(QueryKiller()->QueryName()) + " que le da de lleno.\n"), QueryKiller());
        SetSpellName("rayo final");
        QueryKiller()->Defend(random(30), DT_ELECTRO, DEFEND_SPELL);
        SetSpellName(0);
    }
    ::Die(silent);
}
