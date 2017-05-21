/***
fichero: /guilds/guardabosques/pnj/ledtha.c
30/08/2004 kastwey@simauria. Añadida una comprobación en el aprender y
entrenar para que solo lo haga con miembros del gremio.
Corregido un tipo en las líneas de parada de ataque.
***/

#include <living.h>
#include <properties.h>
#include <money.h>
#include <skills.h>
#include "path.h"

inherit "/std/npc";


#define AoO (TP->QueryGender()==GENDER_FEMALE?"a":"o")

int calc_price(string hab)
{
  return TP->QueryMaxSkillLevel(hab)*1500;
}
#define allow_learn   ([\
  "identificar":HAB_IDPLANTAS;  NIV_IDPLANTAS_GUARDABOSQUES;  MAX_IDPLANTAS_GUARDABOSQUES,\
  "lanzar":     HAB_LANZAR;     NIV_LANZAR_GUARDABOSQUES;     MAX_LANZAR_GUARDABOSQUES,\
  "rastrear":   HAB_RASTREAR;   NIV_RASTREAR_GUARDABOSQUES;   MAX_RASTREAR_GUARDABOSQUES,\
  "cuchillo":   HAB_CUCHILLO;   NIV_CUCHILLO_GUARDABOSQUES;   MAX_CUCHILLO_GUARDABOSQUES,\
  "vara":       HAB_VARA;       NIV_VARA_GUARDABOSQUES;       MAX_VARA_GUARDABOSQUES,\
  "lanza":      HAB_LANZA;      NIV_LANZA_GUARDABOSQUES;      MAX_LANZA_GUARDABOSQUES,\
  "ocultarse":  HAB_OCULTARSE;  NIV_ESCONDERSE_GUARDABOSQUES; MAX_ESCONDERSE_GUARDABOSQUES,\
  "arco":       HAB_ARCO;       NIV_ARCO_GUARDABOSQUES;       MAX_ARCO_GUARDABOSQUES,\
  "bálsamo":    HAB_BALSAMO;    NIV_BALSAMO_GUARDABOSQUES;    MAX_BALSAMO_GUARDABOSQUES,\
  "espada":     HAB_ESPADA;     NIV_ESPADA_GUARDABOSQUES;     MAX_ESPADA_GUARDABOSQUES,\
  "esquivar":   HAB_ESQUIVAR;   NIV_ESQUIVAR_GUARDABOSQUES;   MAX_ESQUIVAR_GUARDABOSQUES,\
  "experto":    HAB_EXPERTISE;  NIV_EXPERTISE_GUARDABOSQUES;  MAX_EXPERTISE_GUARDABOSQUES,\
  "parada":     HAB_PARADA;     NIV_PARADA_GUARDABOSQUES;     MAX_PARADA_GUARDABOSQUES,\
  "daño":       HAB_MASDANYO;   NIV_MASDANYO_GUARDABOSQUES;   MAX_MASDANYO_GUARDABOSQUES,\
  "danyo":      HAB_MASDANYO;   NIV_MASDANYO_GUARDABOSQUES;   MAX_MASDANYO_GUARDABOSQUES,\
  "reflejos":   HAB_REFLEXES;   NIV_REFLEXES_GUARDABOSQUES;   MAX_REFLEXES_GUARDABOSQUES,\
  "preparar bálsamo":HAB_DO_BALSAMO; NIV_DO_BALSAMO_GUARDABOSQUES; MAX_DO_BALSAMO_GUARDABOSQUES,\
      ])
//  "aposito":HAB_APOSITO;17])
#define AL_HAB  0
#define AL_NIV  1
#define AL_MAX  2

int cmd_aprender(string mhab)
{
  int price;
  string hab;

  if (TP->QueryGuild() != GC_GUARDABOSQUES)
  return notify_fail(W("Ledtha te dice: Pero " + capitalize(TP->QueryName()) + "! Tu no perteneces a este gremio. No me está permitido enseñarte habilidades.\n"));

  if (!mhab) return notify_fail(W("Ledtha te dice: ¿Qué habilidades quieres "
    "que te enseñe? Si no sabes cuales hay, puedes leer el cartel.\n"));

  if (!member(allow_learn, mhab))
    return notify_fail("Ledtha te dice: Lo siento, no conozco esa habilidad.\n");

  hab=allow_learn[mhab,0];
  if (member(TP->QuerySkills(), hab)){
    if (TP->QuerySkillLevel(hab)<allow_learn[mhab,AL_MAX])
      return notify_fail(W("Ledtha te dice: Ya conoces esa habilidad. Si lo que "
      "quieres es aumentar tu conocimiento, siempre puedo entrenarte.\n"));
    else return notify_fail(W("Ledtha te dice: Ya conoces todo lo que te puedo "
      "enseñar sobre esa habilidad.\n"));
  }
  if (TP->QueryGuildLevel()<allow_learn[mhab,AL_NIV]) {
    return notify_fail(W("Ledtha te dice: Lo siento, no tienes el nivel suficiente "
      "para que te enseñe esta habilidad.\n"));
  }

  price=allow_learn[mhab,AL_NIV]*2500;

  if (MONEY_LIB->QuerySomeonesValue(TP)<price)
    return notify_fail("Ledtha te dice: Desgraciadamente el aprendizaje no "
      "es gratis, y al parecer no tienes suficiente dinero para pagarlo. "
      "Vuelve cuando tengas "+
      MONEY_DEMON->QueryValueString(price)+".\n");

  write(MONEY_LIB->PayValueString(TP, price, 0, "por el "
    "aprendizaje de la habilidad '"+hab+"'"));

  TP->AddSkill(hab, 1, P_DEX, 2*(allow_learn[mhab,AL_MAX])/3);

  return 1;
}

int cmd_entrenar(string mhab)
{
  string hab;
  int price, lvl;

  if (TP->QueryGuild() != GC_GUARDABOSQUES)
  return notify_fail(W("Ledtha te dice: pero " + capitalize(TP->QueryName()) + "! no eres miembro del gremio.  no me está permitido ayudarte a entrenar tus habilidades.\n")),0;
  if (!mhab) return notify_fail("Ledtha te dice: ¿Que habilidad quieres entrenar?\n"),0;

  hab = allow_learn[mhab];
  if (member(HAB_GUARDABOSQUES, hab)==-1)
    return notify_fail("Ledtha te dice: Lo siento, esa habilidad queda fuera "
      "del alcance de mi enseñanza.\n"),0;

  if (!TP->SkillIsEnabled(hab))
    return notify_fail("Ledtha te dice: No tienes esa habilidad, "+
      TP->QueryName()+".\n"),0;

  if (TP->QuerySkillLevel(hab)+3<TP->QueryMaxSkillLevel(hab))
    return notify_fail("Ledtha te dice: Aún no estas preparad"+AoO+" para "
      "que te enseñe a mejorar esa habilidad.\n"),0;

  price=calc_price(hab);
  if (!price)
    return notify_fail("Ledtha te dice: No puedes entrenar esa habilidad.\n"),0;
  if (MONEY_LIB->QuerySomeonesValue(TP)<price)
    return notify_fail("Ledtha te dice: Nada es gratis, tienes que pagar "+
      MONEY_DEMON->QueryValueString(price)+" por los gastos.\n"),0;

  write(MONEY_LIB->PayValueString(TP, price, 0, "por el "
    "entrenamiento de la habilidad '"+hab+"'"));

  write("Ledtha te dice: Con mi ayuda ahora puedes seguir aprendiendo tu "
    "habilidad.\n");
/*
  lvl=TP->QueryMaxSkillLevel(hab)+10;
  if (lvl>100) lvl=100;
*/
  TP->SetMaxSkillLevel(hab, allow_learn[mhab,AL_MAX]);
  return 1;
}


create()
{
  ::create();
  SetStandard("Ledtha", "elfo", 20, GENDER_FEMALE);
  SetLong(W("Ledtha es la hermana de Safras, y al igual que ella es también "
    "muy hermosa, aunque algo más joven y más fuerte, aunque bien "
    "proporcionada. Su pelo, al contrario que Safras, es rizado, con "
    "tonalidades cobrizas. Su trabajo en el gremio es enseñar a los "
    "miembros las habilidades cuando éstos ya han llegado a su límite, "
    "pero cuando todavía pueden aprenderla mejor.\n"));
  SetShort("Ledtha, la Maestra de Combate");
  InitChats(1, ({ "Ledtha dice: Puedo entrenar tus habilidades de combate con el comando 'entrenar'.\n",
    "Ledtha se mesa el rizado cabello.\n",
    "Ledtha empieza a entrenarse.\n",
    "Ledtha te dice: Si quieres entrenarte no tienes más que decirmelo.\n",
    "Ledtha coge una vara y empieza a aporrear a un saco de entrenamiento.\n",
    "Ledtha coge una espada y se pone a cortar el aire a una velocidad pasmosa.\n",
    "Ledtha se sienta en un sillón y se pone a leer.\n"}));
  Set(P_CANT_FIGHT,W("Ledtha detiene tu ataque, se concentra y un fino aura realza su "
    "contorno. Te sientes calmado y en paz.\n"));
}

init()
{
  ::init();
  add_action("cmd_entrenar", "entrenar");
  add_action("cmd_aprender", "aprender");
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
  say("Ledtha detiene tu ataque, se concentra y un fino aura realza su "
    "contorno. Te sientes calmado y en paz.\n");
  StopAllHunting();
  return 0;
}
int QueryHP()
{
  return 178;
}