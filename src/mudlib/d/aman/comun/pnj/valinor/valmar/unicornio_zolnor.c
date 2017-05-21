/*****************************************************************************************
 ARCHIVO:       unicornio_zolnor.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCI�N:   Es el �nico unicornio que queda en estos parajes, va a ser muy muy duro.
 COMENTARIOS: Curar leves 3 veces por d�a
              Curar moderadas 1 vez al d�a
              Circulo m�gico contra el mal
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

/* DECLARACI�N DE FUNCIONES */

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
    SetLong("Una visi�n celestial se encuentra ante tus ojos, se trata de un magn�fico "
        "unicornio, una criatura dotada de una inagotable fuente de magia, bondad y "
        "pureza. Su poderosa presencia parece atraer hacia s� toda la luz del ambiente y "
        "reflejarla a la vez. Su aspecto asemeja al de un gran caballo de pelaje "
        "absolutamente blanco, sus largas crines y barbas plateadas, sus grandes cascos "
        "hendidos y su larga cola leonina marcan la diferencia, pero sin lugar a dudas, "
        "lo que m�s llama la atenci�n de este maravilloso ser es el largo cuerno de "
        "forma espiral y brillo nacarado que surge del centro de su frente. Unos grandes "
        "ojos m�s azules que el m�s puro de los zafiros te observan con brillo "
        "inteligente, vigilando con atenci�n todos tus movimientos.\n");
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
    say(TC_BOLD TC_BLACK "El c�rculo m�gico forma una espiral y se "
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

        //De momento s�lo tiene �ste
        case  1: /* C�RCULO M�GICO CONTRA EL MAL */

              if (!circulo_magico)
              {
                  if (QuerySP() < 100) return 0;
                      break;

                  AddSP(-100);
                  say(TC_BOLD TC_CYAN "�Zolnor comienza a mover una de sus patas en "
                      "c�rculo y un fino aura azulado aparece a su alrededor!\n"
                      TC_NORMAL);
                  circulo_magico = 1;
                  call_out("desvanecer_escudo", 20);
                  return 1;
              }
              break;

            }
    return 1;
}
