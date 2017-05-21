/***
fichero: /guilds/guardabosques/pnj/safras.c
30/08/2004 kastwey@simauria. Añadida una comprobación en el aprender y
entrenar para que solo lo haga con miembros del gremio.
***/
#include <living.h>
#include <properties.h>
#include <money.h>
#include "path.h"

inherit "/std/npc";

#define AoO (TP->QueryGender() == GENDER_FEMALE ? "a" : "o")

int calc_price(string hab)
{
  return TP->QueryMaxSpellLevel(hab)*1500;
}

#define allow_learn (["calmar":MAG_CALMAR;8,"convocar":MAG_CONVOCAR;10,\
	"corteza":MAG_CORTEZA;5,"sangre":MAG_SANGRE;15,"piedra":MAG_PIEDRA;15,\
    "miedo":MAG_MIEDO;25,\
    "transmutar":MAG_TRANSMUTAR;20,"hierro":MAG_HIERRO;30])

int cmd_aprender(string mhab)
{
  int price;
  string hab;

  if (TP->QueryGuild() != GC_GUARDABOSQUES)
  return notify_fail(W("Safras te dice: Pero " + capitalize(TP->QueryName()) + "! Tu no eres miembro de este gremio. No puedo enseñarte habilidades mágicas.\n"));
  if (!mhab) return notify_fail("Safras te dice: ¿Qué habilidades mágicas "
  	"quieres que te enseñe? Si no sabes cuales hay, puedes leer el "
  	"cartel.\n");

  if (!member(allow_learn, mhab))
    return notify_fail("Safras te dice: Lo siento, no conozco esa magia.\n");

  hab=allow_learn[mhab,0];
  if (member(TP->QuerySpells(), hab))
    return notify_fail("Safras te dice: Ya conoces esa habilidad. Si lo que "
    	"quieres es aumentar tu conocimiento, siempre puedo entrenarte.\n");

  if (TP->QueryGuildLevel()<allow_learn[mhab,1])
  {
    return notify_fail("Safras te dice: Lo siento, no tienes el nivel suficiente "
    	"para que te enseñe esta habilidad.\n");
  }

  price=allow_learn[mhab,1]*1000;

  if (MONEY_LIB->QuerySomeonesValue(TP)<price)
    return notify_fail("Safras te dice: Desgraciadamente el aprendizaje no "
    	"es gratis, y al parecer no tienes suficiente dinero para pagarlo. "
    	"Vuelve cuando tengas "+
    	MONEY_DEMON->QueryValueString(price)+".\n");

  write(MONEY_LIB->PayValueString(TP, price, 0, "por el "
  	"aprendizaje de la habilidad mágica '"+hab+"'"));

  TP->AddPlayerSpell(hab, 1, 60, P_INT);

  return 1;

}

int cmd_entrenar(string mhab)
{
  int price, lvl;
  string hab;

  if (TP->QueryGuild() != GC_GUARDABOSQUES)
  return notify_fail(W("Safras te dice: Pero " + capitalize(TP->QueryName()) + "! Tu no eres miembro de este gremio. No puedo añudarte a entrenar ninguna habilidad mágica.\n"));


  if(!mhab) return notify_fail("Safras te dice: ¿Qué magia quieres entrenar?\n");

  if (member(TP->QuerySpells(), mhab))
    hab=mhab;
  else if (member(magia, mhab))
    hab=magia[mhab];
  else
    return notify_fail("Safras te dice: Lo siento, desconozco esa "
    	"magia, no puedo ayudarte.\n");

  if (!TP->SpellIsEnabled(hab))
    return notify_fail("Safras te dice: No tienes esa habilidad mágica, "
    	"no puedo enseñarte a usarla mejor.\n");

  if (TP->QuerySpellLevel(hab)+1<TP->QueryMaxSpellLevel(hab))
  {
    notify_fail("Safras te dice: Todavía no estas preparad"+AoO+" para "
    	"entrenar esa magia.\n");
    return 0;
  }

  price=calc_price(hab);
  if (!price)
    return notify_fail("Safras te dice: No puedes entrenar esa habilidad.\n");

  if (MONEY_LIB->QuerySomeonesValue(TP)<price)
    return notify_fail("Safras te dice: Desgraciadamente el entrenamiento no "
    	"es gratis, y al parecer no tienes suficiente dinero para pagarlo. "
    	"Vuelve cuando tengas "+
    	MONEY_DEMON->QueryValueString(price)+".\n");

  write(MONEY_LIB->PayValueString(TP, price, 0, "por el "
  	"entrenamiento de la habilidad mágica '"+hab+"'"));

  write(W("Safras te dice: Con mis consejos puedes seguir aumentando el "
  	"nivel de tu habilidad.\n"));
  lvl=TP->QueryMaxSpellLevel(hab)+10;
  if (lvl>100) lvl=100;

  TP->SetMaxSpellLevel(hab, lvl);
//  dtell("diox", "Poniendo el nivel máximo de '"+hab+"' a "+lvl+".\n");
  return 1;
}

create()
{
  ::create();
  SetStandard("Safras", "elfo", 20, GENDER_FEMALE);
  SetLong(W("Safras es una elfa bastante hermosa y de unas medidas bien "
  	"proporcionadas. Su tarea en el gremio, al igual que su hermana "
  	"Ledtha, es enseñar nuevas maneras de usar sus habilidades mágicas "
  	"para que éstos puedan seguir aprendiendo.\n"));
  InitChats(1, ({
  	"Safras te dice: Puedo entrenar tus habilidades mágicas si así lo deseas.\n",
  	"Safras coge un libro de una estantería y se pone a leerlo con detenimiento.\n",
  	"Oyes un murmullo. Te das cuenta de que es Safras quien lo origina.\n",
  	"Safras se concentra y empieza a recitar unos versículos.\n",
  	"La Maestra se sienta y empieza a leer.\n"}));
  SetShort("Safras, la Maestra de Magia");
}

init()
{
  ::init();
  add_action("cmd_entrenar", "entrenar");
  add_action("cmd_aprender", "aprender");
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
  say("Safras detiene tu ataque, se concentra vislumbras su aura. Te sientes "
  	"como un estúpido y detienes tu ataque.\n");
  StopAllHunting();
  return 0;
}

int QueryHP()
{
  return 178;
}