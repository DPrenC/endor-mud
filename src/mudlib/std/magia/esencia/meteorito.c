/* SIMAURIA '/std/magia/esencia/meteorito.c'
   =========================================
   [w] Woo@simauria

   05-04-00 [w] Nuevo conjuro.
   08-06-00 [w] Ahora solo puedes hacerlo en un lugar cerrado.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <skills.h>
#include <combat.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Meteorito");
  SetSpellUse("contra <objetivo>");
  SetSpellType(ST_DAMAGE);
  SetSPCost(40);
  SetCastLevel(GC_CONJURADORES,7);
  SetMemorizeLevel(GC_CONJURADORES,22);
  SetTiredTime(1);
  SetSpellXP(20);
  SetSpellDescription(
   "Lanzas una tromba de meteoritos tu oponente.\n");
 }

mixed Check(object caster, string args) {
  string quien;
  object enemigo;

  if (!sizeof(args) || sscanf(args,"contra %s", quien)!=1)
    return notify_fail("¿Contra quién quieres lanzar el conjuro?\n");

  if (!enemigo=present(quien, environment(caster)))
    return notify_fail("No puedes ver a "+quien+" aquí.\n");

  if (!living(enemigo))
    return notify_fail("No creo que a eso le afecte mucho.\n");

  if(enemigo==caster)
    return notify_fail("¿Quieres suicidarte?\n");

  if (!CanCastSpell(enemigo)) return 0;

  return enemigo;
}

int Cast(object caster, mixed enemigo) {
 int danyo;
    int acierto;

	acierto = caster->QueryGuildLevel();
	acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
	if (acierto>100) acierto = 100;

 if (acierto<=15)	danyo = TP->QueryInt()+acierto/2;
 else if (acierto<=60)	danyo = TP->QueryInt()+acierto;
 else 			danyo = TP->QueryInt()+acierto*3/2;

  play_sound(ENV(caster),SND_MAGIA("meteorito.mp3"));
  write(W("Cierras los ojos y concentras tus fuerzas en tu interior. Al instante "
    "creas una tromba de meteoritos que impactan en "+enemigo->QueryName()+
    ".\n"));

  say(W(capitalize(caster->QueryName())+" cierra los ojos. "
    "Al instante crea una tromba de meteoritos que impactan en "
    +enemigo->QueryName()+".\n"),({enemigo,caster}));

  tell_object(enemigo,W(capitalize(caster->QueryName())+" cierra los ojos. "
    "Al instante crea una tromba de meteoritos que te dan de lleno ¡¡CLOCK!!.\n"));

  if (danyo > (125+TP->QueryInt()) ) danyo=125+TP->QueryInt();
  enemigo->AddEnemy(TP);
  enemigo->Defend(danyo, TM_CALOR, DEFEND_SPELL);

  return 1;
}


int Fail(object caster, mixed enemigo) {
  object piedra;

  play_sound(environment(caster),SND_MAGIA("fallarmeteorito.mp3"));
  write(W("Miras al cielo y concentras tus fuerzas en un punto. Al instante "
    "ves aproximarse del cielo una bola de fuego que cae al suelo sin producir daños.\n"));

  say(W(capitalize(caster->QueryName())+" mira al cielo y se concentra en un punto fijo. "
    "Al instante ves aproximarse del cielo una bola de fuego que impacta en "
    "el suelo sin producir daños considerables.\n"),({enemigo,caster}));

  seteuid(getuid(TO));
  piedra=clone_object("/std/thing");
  piedra->SetShort("un meteorito");
  piedra->SetLong("Es un meteorito todavia humeante.\n");
  piedra->AddAdjective(({"humeante"}));
  piedra->AddId("meteorito");
  piedra->SetValue(0);
  piedra->SetWeight(40000);
  seteuid(0);

  piedra->move(environment(TP),M_DROP);

  return 1;
}


