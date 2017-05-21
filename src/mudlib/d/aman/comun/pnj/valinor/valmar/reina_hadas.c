/*****************************************************************************************
 ARCHIVO:       reina_hadas.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCIÓN:   Twyligh, reina de las hadas.
 COMENTARIOS:

*****************************************************************************************/

#include "./path.h"
#include <spellmonster.h>
#include <combat.h>
#include <colours.h>
#include <properties.h>
#include <gremios.h>

#define EXCLUDE_DAMAGE_TYPES ({MT_INTR, MT_SLASH, MT_BLUDGEON, MT_PIERCE, MT_FIRE, \
                               MT_ELECTRO, MT_WATER, MT_GAS, MT_ZAP, MT_ACID, MT_POISON, \
                               MT_PSYCHO, MT_NOAIR})

inherit SPELLMONSTER;

/* VARIABLES GLOBALES */

static string pSpellName;
int escudo = 0;

/* DECLARACIÓN DE FUNCIONES */

public string f_charlar();
public status check_sp();
public string SetSpellName(string conj);
public string QuerySpellName();
public void desvanecer_escudo();
public int magia();

/****************************/

create()
{
    if(::create()) return 1;

    SetStandard("twyligh", "duende", ([GC_CONJURADOR: 85 + d10()]), GENERO_FEMENINO);
    AddId(({"hada", "reina", "reina_faeria"}));
    SetShort("twyligh, la reina");
    SetLong("La dorada cabellera le cae hasta el suelo, en una cascada de ondulantes "
        "rizos, formando un halo de luz alrededor de ella. Sus ojos, de un gris plateado, "
        "brillan más fríos y resplandecientes que las estrellas de la noche. Su cuerpo "
        "desnudo, tan suave, pálido y terso, está cubierto de flores. Y esas flores que "
        "podrían haber sido usadas para ocultar con recato su desnudez, tienen "
        "precisamente un efecto totalmente contrario. Racimos de rosas y lilas sujetan "
        "sus blancos pechos. Hileras de caléndulas le cruzan el liso estómago y le "
        "acarician las bien proporcionadas piernas. Al primer golpe de vista, parece "
        "joven, aunque en seguida se nota que no lo es: tiene canas entre los cabellos "
        "de oro y unas ligeras arrugas entre las comisuras de los ojos.\n");
    SetSmell("El olor de las rosas, lilas, caléndulas y crisantemos te embriaga.\n");
    InitChats(2, ({SF(f_charlar)}));
    SetSpellChance(30);
    SetKillXP(400000);
    SetSP(1700);
    SetAggressive(0);
    AddSpell("conjuros",
        ([
            S_CHECKFUN: SF(check_sp),
            S_FUN: SF(magia),
            S_SP:2,
            S_CHANCE: 1000,
            S_VICTIMS: 1,
        ]));
}

public string f_charlar()
{
    string msgs_malos, msgs_buenos;

    switch(d2())
    {
        case 1:
             msgs_malos = "Twyligh te mira con cara de asco.\n";
             msgs_buenos = "Twyligh te mira y sonríe.\n";
             break;
        case 2:
             msgs_malos = TC_TEL_WHO "Twyligh dice:" TC_TEL_MSG " No suelo hacer tratos "
                          "con los de tu raza.\n" TC_NORMAL;
             msgs_buenos = TC_TEL_WHO "Twyligh dice:" TC_TEL_MSG " ¡Me encanta bailar!\n" 
                           TC_NORMAL;
             break;
    }

    filter(all_inventory(environment()),
           (: if (query_once_interactive($1))
              {
                 if(member(RAZASENEMIGAS, $1->QueryRace()) >= 0)
                 {
                     tell_object($1, $2);
                     return 0;
                 }
                 tell_object($1, $3);
                 return 0;
             }
             return 0;
           :), msgs_malos, msgs_buenos);
}

//Funciones para ser defendida por Ruergh:

public int QueryIsProtected() { return 1; }

public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    filter(all_inventory(environment()), (: call_other($1, "QueryIsProtected") &&
        member($2->QueryEnemies(), $1) < 0 ? $1->AddEnemy($2):0 :), TP || PO);
    return ::Defend(dam, dam_type, flags, &xtras);
}

//Funciones para la magia:

public status check_sp() { return QuerySP() > 0; }

public string SetSpellName(string conj) { return pSpellName = conj; }
public string QuerySpellName() { return pSpellName; }

public void desvanecer_escudo()
{
    say(TC_BOLD TC_BLACK "El escudo gélido desaparece.\n" TC_NORMAL);
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
        case   0..24: /* FUEGO DE HADAS */

              if(QuerySP() < 50)
                  break;

              AddSP(-50);
              pv = 20 + random(QueryInt());
              tell_object(enemigo, "La Reina apunta al suelo con el dedo. Twyligh "
                  "dice: " TC_BOLD TC_CYAN "\"Naur na ibualá\".\n"
                  TC_NORMAL "Al instante aparece un círculo de llamas a tu "
                  "alrededor que te quema.\n");
              tell_room(ENV(TO), "La Reina apunta al suelo con el dedo. Twyligh dice: "
                  TC_BOLD TC_CYAN "\"Naur na ibualá\"" TC_NORMAL ".\nAl instante "
                  "aparece un círculo de llamas alrededor de "
                  + CAP(NNAME(enemigo)) + " que le quema.\n", ({enemigo, TO}));
              SetSpellName("Fuego de Hadas");
              enemigo->Defend(pv, TM_CALOR, DEFEND_SPELL);
              SetSpellName(0);

              break;

        case  25..49: /* DANZA IRRESISTIBLE */

              if (QuerySP() < 20)
                  break;

              AddSP(-20);
              tell_object(enemigo, "Twyligh te mira  y pronuncia las palabras 'Pal Coire "
                  "Mereth'. De repente, tus pies toman vida propia y empiezan a moverse "
                  "al compás de una música inexistente....\n");
              tell_room(ENV(TO), "Twyligh mira a " + CAP(NNAME(enemigo)) + " y pronuncia "
                  "las palabras 'Pal Coire Mereth'. De repente, sus pies toman vida "
                  "propia y empiezan a moverse al compás de una música inexistente...\n",
                  ({enemigo, TO}));
              SetSpellName("danza irresistible");
              enemigo->SetCombatDelay(2, "A causa del baile de los pies, no te puedes "
                                         "concentrar en el ataque...\n");
              SetSpellName(0);

              break;

        case  50..74: /* ESCUDO GÉLIDO */

              if (!escudo)
              {
                  if (QuerySP() < 70)
                      break;

                  AddSP(-70);
                  say(TC_BOLD TC_PURPLE "¡¡¡Twyligh conjura 'ESCUDO GÉLIDO' y se "
                      "envuelve en un escudo de llamas frías!!!.\n" TC_NORMAL);
                  escudo = 1;
                  call_out("desvanecer_escudo", 12);
              }
              break;
        case  75..99: /* ROCIADA PRISMÁTICA */

              if (QuerySP() < 50)
                  break;

              AddSP(-50);
              switch(random(14))
              {
                  case   0..1: /* ROJO */

                         tell_object(enemigo, TC_BOLD TC_RED "Twyligh abre la mano y un "
                             "haz de pequeños prismas de color rojo escarlata brota de "
                             "sus dedos e impacta de lleno sobre ti." TC_NORMAL "\n" );
                         tell_room(ENV(TO), TC_BOLD TC_RED "Twyligh abre la mano "
                             "y un haz de pequeños prismas de color rojo escarlata brota "
                             "de sus dedos e impacta de lleno sobre " +
                             CAP(NNAME(enemigo)) + TC_NORMAL ".\n", ({enemigo, TO}));
                         SetSpellName("Rociada prismática bermellona");
                         enemigo->Defend(20, TD_CALOR, DEFEND_SPELL);
                         SetSpellName(0);
                         break;

                  case   2..3: /* NARANJA */

                         tell_object(enemigo, TC_YELLOW "Twyligh abre la mano y un haz "
                             "de pequeños prismas de color dorado brota de sus dedos e "
                             "impacta de lleno sobre ti." TC_NORMAL "\n");
                         tell_room(ENV(TO), TC_YELLOW "Twyligh abre la mano y un haz de "
                             "pequeños prismas de color dorado brota de sus dedos e "
                             "impacta de lleno sobre " + CAP(NNAME(enemigo)) +
                             TC_NORMAL ".\n", ({enemigo, TO}));
                         SetSpellName("Rociada prismática dorada");
                         enemigo->Defend(40, TD_ACIDO, DEFEND_SPELL);
                         SetSpellName(0);
                         break;

                  case   4..5: /* AMARILLO */

                         tell_object(enemigo, TC_BOLD TC_YELLOW "Twyligh abre la mano y "
                             "un haz de pequeños prismas de color amarillo oro brota de "
                             "sus dedos e impacta de lleno sobre ti." TC_NORMAL "\n");
                         tell_room(ENV(TO), TC_BOLD TC_YELLOW "Twyligh abre la mano y un "
                             "haz de pequeños prismas de amarillo oro brota de sus dedos "
                             "e impacta de lleno sobre " + CAP(NNAME(enemigo)) +
                             TC_NORMAL ".\n", ({enemigo, TO}));
                         SetSpellName("Rociada prismática áurea");
                         enemigo->Defend(50, TD_ELECTRICIDAD, DEFEND_SPELL);
                         SetSpellName(0);
                         break;

                  case   6..7: /* VERDE */

                         tell_object(enemigo, TC_BOLD TC_GREEN "Twyligh abre la mano y "
                             "un haz de pequeños prismas de color verde brota de sus "
                             "dedos e impacta de lleno sobre ti." TC_NORMAL "\n");
                         tell_room(ENV(TO), TC_BOLD TC_GREEN "Twyligh abre la mano y un "
                             "haz de pequeños prismas de color verde brota de sus dedos "
                             "e impactan de lleno sobre " + CAP(NNAME(enemigo)) +
                             TC_NORMAL ".\n", ({enemigo, TO}));
                         SetSpellName("Rociada prismática lima-limón");
                         enemigo->Defend(20, TD_VENENO, DEFEND_SPELL);
                         SetSpellName(0);
                         break;

                  case   8..9: /* AZUL */

                         tell_object(enemigo, TC_BOLD TC_CYAN "Twyligh abre la mano y un "
                             "haz de pequeños prismas de color azul brota de sus dedos e "
                             "impacta de lleno sobre ti." TC_NORMAL "\n");
                         tell_room(ENV(TO), TC_BOLD TC_CYAN "Twyligh abre la mano y un "
                             "haz de pequeños prismas de color azul brota de sus dedos e "
                             "impacta de lleno sobre " + CAP(NNAME(enemigo)) +
                             TC_NORMAL ".\n", ({enemigo, TO}));
                         SetSpellName("Rociada prismática celeste");
                         enemigo->Defend(30, TD_FRIO, DEFEND_SPELL);
                         SetSpellName(0);
                         break;

                  case   10..11: /* AÑIL */

                         tell_object(enemigo, TC_BOLD TC_BLUE "Twyligh abre la mano y un "
                             "haz de pequeños prismas de color azul índigo brota de sus "
                             "dedos e impacta de lleno sobre ti." TC_NORMAL "\n");
                         tell_room(ENV(TO), TC_BOLD TC_BLUE "Twyligh abre la mano y un "
                             "haz de pequeños prismas de color azul índigo brota de sus "
                             "dedos e impacta de lleno sobre " + CAP(NNAME(enemigo)) +
                             TC_NORMAL ".\n", ({enemigo, TO}));
                         SetSpellName("Rociada prismática marina");
                         enemigo->Defend(30, TD_AGUA, DEFEND_SPELL);
                         SetSpellName(0);
                         break;

                  case 12..13: /* VIOLETA */

                         tell_object(enemigo, TC_BOLD TC_PURPLE "Twyligh abre la mano y "
                             "un haz de pequeños prismas de color morado brota de sus "
                             "dedos e impacta de lleno sobre ti." TC_NORMAL "\n");
                         tell_room(ENV(TO), TC_BOLD TC_PURPLE "Twyligh abre la mano y un "
                             "haz de pequeños prismas de color morado brota de sus dedos "
                             "e impacta de lleno sobre " + CAP(NNAME(enemigo)) +
                             TC_NORMAL ".\n", ({enemigo, TO}));
                         SetSpellName("Rociada prismática púrpura");
                         enemigo->Defend(20, TD_GAS, DEFEND_SPELL);
                         SetSpellName(0);
                         break;

                  default: break;
              }
        default: break;
    }
}

public varargs int DoDamage(int damage, int type, int gentle, mixed xtras)
{
    //Los conjuros no se ven afectados por el escudo

    if (escudo && member(EXCLUDE_DAMAGE_TYPES, type) < 0)
    {
        tell_object(TP, TC_BOLD TC_WHITE "El escudo gélido te quema.\n" TC_NORMAL);
        say(TC_BOLD TC_WHITE "El escudo gélido quema a "
           + CAP(TNAME) + ".\n" TC_NORMAL, TP);
        TP->Defend(TP->QueryStr() + random(10), TM_FRIO, 1000);
    }
    return ::DoDamage(damage, type, gentle, &xtras);
}
