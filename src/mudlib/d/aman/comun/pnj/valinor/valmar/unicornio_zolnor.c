/*****************************************************************************************
 ARCHIVO:       unicornio_zolnor.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCIÓN:   Es el único unicornio que queda en estos parajes, va a ser muy muy duro.
 COMENTARIOS: Curar leves 3 veces por día
              Curar moderadas 1 vez al día
              Circulo mágico contra el mal
   \
   _\,,
  "-=\~     _
     \\~___( ~
    _|/---\\_
    \        \
*****************************************************************************************/

#include "./path.h"
#include <spellmonster.h>
#include <colours.h>
#include <properties.h>
#include <gremios.h>

inherit SPELLMONSTER;

static string pSpellName;
private int circulo_magico = 0;

/* DECLARACIÓN DE FUNCIONES */

public status check_sp();
public string SetSpellName(string conj);
public string QuerySpellName();
public void desvanecer_circulo();
public int magia();

/****************************/

create()
{
    if(::create()) return 1;

    SetStandard("zolnor", "unicornio", ([GC_GUARDABOSQUE: 90]), GENERO_MASCULINO);
    SetShort("zolnor, el Rey del Bosque");
    SetLong("Una visión celestial se encuentra ante tus ojos, se trata de un magnífico "
        "unicornio, una criatura dotada de una inagotable fuente de magia, bondad y "
        "pureza. Su poderosa presencia parece atraer hacia sí toda la luz del ambiente y "
        "reflejarla a la vez. Su aspecto asemeja al de un gran caballo de pelaje "
        "absolutamente blanco, sus largas crines y barbas plateadas, sus grandes cascos "
        "hendidos y su larga cola leonina marcan la diferencia, pero sin lugar a dudas, "
        "lo que más llama la atención de este maravilloso ser es el largo cuerno de "
        "forma espiral y brillo nacarado que surge del centro de su frente. Unos grandes "
        "ojos más azules que el más puro de los zafiros te observan con brillo "
        "inteligente, vigilando con atención todos tus movimientos.\n");
    AddId(({"rey", "rey del bosque"}));

    SetAggressive(0);
    SetWhimpy(0);

    SetCastChance(20);

    AddSpell("conjuros",
        ([
            S_CHECKFUN: SF(check_sp),
            S_FUN: SF(magia),
            S_SP:2,
            S_CHANCE: 1000,
            S_VICTIMS: 1,
        ]));
}

public status check_sp() { return QuerySP() > 0; }

public string SetSpellName(string conj) { return pSpellName = conj; }
public string QuerySpellName() { return pSpellName; }

public void desvanecer_circulo()
{
    say(TC_BOLD TC_BLACK "El círculo mágico forma una espiral y se "
        "desvanece.\n" TC_NORMAL);
    circulo_magico = 0;
}

public int magia()
{
    int pv;
    object *adversarios, enemigo;
    adversarios = QueryEnemies() || ({});
    if(!sizeof(adversarios)) return 0;
    enemigo = adversarios[random(sizeof(adversarios))];

    switch (d2())
    {

        //De momento sólo tiene éste
        case  1: /* CÍRCULO MÁGICO CONTRA EL MAL */

              if (!circulo_magico)
              {
                  if (QuerySP() < 100) return 0;
                      break;

                  AddSP(-100);
                  say(TC_BOLD TC_CYAN "¡Zolnor comienza a mover una de sus patas en "
                      "círculo y un fino aura azulado aparece a su alrededor!\n"
                      TC_NORMAL);
                  circulo_magico = 1;
                  call_out("desvanecer_escudo", 20);
                  return 1;
              }
              break;

            }
    return 1;
}
