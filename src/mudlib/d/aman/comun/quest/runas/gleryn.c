/*****************************************************************************************no funciona
orome: no funciona y de momento no voy a arreglarlo.
 ARCHIVO:       gleryn.c
 AUTOR:         Ztico
 FECHA:         17-01-2006
 DESCRIPCIÓN:   Gleryn, el hechicero
 COMENTARIOS:   QUEST_KEY: santuario_druida_quest
*****************************************************************************************/

#include "./path.h"
#include "./runas_quest.h"
#include <spellmonster.h>
#include <gremios.h>
#include <properties.h>
#include <colours.h>
#include <combat.h>
#include <moving.h>

#define EXCLUDE_DAMAGE_TYPES ({MT_INTR, MT_SLASH, MT_BLUDGEON, MT_PIERCE, MT_FIRE, \
                               MT_ELECTRO, MT_WATER, MT_GAS, MT_ZAP, MT_ACID, MT_POISON, \
                               MT_PSYCHO, MT_NOAIR})

inherit SPELLMONSTER;

static string pSpellName;
int escudo = 0;

/* DECLARACIÓN DE FUNCIONES */

public status check_sp();
public string SetSpellName(string conj);
public string QuerySpellName();
public void desvanecer_escudo();
public int magia();

/****************************/

public void create()
{
    if(::create()) return;

    SetStandard("gleryn", "elfo", ([GC_CONJURADOR: 30 + random(6)]), GENERO_MASCULINO);
    SetShort("Gleryn, el Hechicero");
    SetLong("Tienes ante tí a Gleryn, el famoso hechicero que traicionó a la Orden de "
         "los Antiguos druidas. Es un elfo alto, rubio y de aspecto bastante demacrado. "
         "Va vestido con una túnica gris, raida y desgastada.\n");
    AddId(({"druida", "hechicero"}));

    SetAggressive(0);
    SetWhimpy(0); //No huye

    SetCastChance(20);
    SetSP(900);

    AddSpell("conjuros",
        ([
            S_CHECKFUN: SF(check_sp),
            S_FUN: SF(magia),
            S_SP:2,
            S_CHANCE: 1000,
            S_VICTIMS: 1,
        ]));

    AddItem(OBJETO "arma/espada-acero.c", REFRESH_REMOVE, SF(wieldme));
}

//Funciones para la magia:

public status check_sp() { return QuerySP() > 0; }

public string SetSpellName(string conj) { return pSpellName = conj; }
public string QuerySpellName() { return pSpellName; }

public void desvanecer_escudo()
{
    say(TC_BOLD TC_BLACK "El escudo de fuego desaparece.\n" TC_NORMAL);
    escudo = 0;
}

public int magia()
{
    int pv;
    object *adversarios, enemigo;
    adversarios = QueryEnemies() || ({});
    if(!sizeof(adversarios)) return 0;
    enemigo = adversarios[random(sizeof(adversarios))];

    switch (random(100))
    {
        case  0..33: /* GOLPE DE DESCARGA */

              if(QuerySP() < 20)
return 1;

              AddSP(-20);
              pv = 20 + random(QueryInt());
              tell_object(enemigo, "Gleryn, el Hechicero clava la vista en ti y "
                  "pronuncia unas palabras.\nGleryn dice: Creil shal dhûl.\nAl instante "
                  "notas como algo invisible te golpea.\n");
              tell_room(ENV(TO), "Gleryn, el Hechicero clava la vista en " +
                  CAP(NNAME(enemigo)) + " y pronuncia unas palabras.\nGleryn dice: Creil "
                  "shal dhûl.\n" + CAP(NNAME(enemigo)) + " retrocede como si hubiese "
                  "sido golpead" + AO + " por algo invisible.\n", ({enemigo,TO}));
              SetSpellName("golpe de descarga");
              enemigo->Defend(pv, TM_APLASTAMIENTO, DEFEND_SPELL);
              SetSpellName(0);
break;
        case  34..66: /* LANZA DE FUEGO */

              if (QuerySP() < 25)
return 1;

              AddSP(-25);
              pv = 30 + random(QueryInt());
              tell_object(enemigo, "Gleryn, el Hechicero cierra los ojos. Al instante "
                  "sientes un calor intenso en la habitación y ves su fuente, una lanza de "
                  "fuego que levita a su lado. De repente, abre los ojos y con un "
                  "movimiento vertiginoso la arroja contra ti.\n");
              tell_room(ENV(TO), "Gleryn, el Hechicero cierra los ojos. Al instante "
                  "sientes un calor intenso en la habitación y ves su fuente, una lanza de "
                  "fuego que levita a su lado. De repente, abre los ojos y con un "
                  "movimiento vertiginoso la arroja contra " + CAP(NNAME(enemigo)) + ".\n",
                  ({enemigo, TO}));
              SetSpellName("lanza de fuego");
              enemigo->Defend(pv, 2*TD_FUEGO, DEFEND_SPELL);
              SetSpellName(0);

              break;

        case  67..99: /* ESCUDO DE FUEGO */

              if (!escudo)
              {
                  if (QuerySP() < 70)
return 1;

                  AddSP(-70);
                  say(TC_BOLD TC_PURPLE "¡Gleryn, el Hechicero conjura 'ESCUDO DE "
                      "FUEGO' y se envuelve en un escudo de llamas!\n" TC_NORMAL);
                  escudo = 1;
                  call_out("desvanecer_escudo", 12);
              }
              break;

        default: break;
    }
}

public varargs int DoDamage(int damage, int type, int gentle, mixed xtras)
{
    //Los conjuros no se ven afectados por el escudo

    if (escudo && member(EXCLUDE_DAMAGE_TYPES, type) < 0)
    {
        tell_object(TP, TC_BOLD TC_WHITE "El escudo de fuego te quema.\n" TC_NORMAL);
        say(TC_BOLD TC_WHITE "El escudo de fuego quema a "
           + CAP(TNAME) + ".\n" TC_NORMAL, TP);
        TP->Defend(TP->QueryStr(), TD_CALOR, 10);
    }
    return ::DoDamage(damage, type, gentle, &xtras);
}

public varargs void Die(int silent)
{
    object killer, runa;

    if (!killer = QueryKiller()) return ::Die(silent);

    if(killer->QueryIsPet() && killer->QueryOwner())
    {
        if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, find_object(killer->QueryOwner())) ||
           !find_object(killer->QueryOwner())->QueryAttribute(ATTE_RUNAS))
            return ::Die(silent);
        runa = clone_object(COMUN "quest/runas/runa_9.c");
        runa->move(TO, M_SILENT);
        runa->SetOwner(NREAL(killer->QueryOwner()));
    }
    else if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, killer) || 
            !killer->QueryAttribute(ATTE_RUNAS))
        return ::Die(silent);
    else
    {
        runa = clone_object(COMUN "quest/runas/runa_9.c");
        runa->move(TO, M_SILENT);
        runa->SetOwner(NREAL(killer));
    }
    return ::Die(silent);
}
