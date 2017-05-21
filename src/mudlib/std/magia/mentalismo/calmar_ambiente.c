/* SIMAURIA '/std/magia/mentalismo/calmar.c'
   =========================================
   [w] Woo@simauria

   04-12-99 [w] Calma a todo ser viviente de un lugar.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <sounds.h>

inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Calmar Ambiente");
  SetSpellUse("");
  SetSpellType(ST_INFLUENCE);
  SetSPCost(25);
  SetCastLevel(GC_CONJURADORES,15);
  SetCastLevel(GC_KISALAS,1);
  SetMemorizeLevel(GC_KISALAS,10);
  SetTiredTime(2);
  SetSaveType(SAVE_TYPE_WILL);
  SetSpellXP(15);
  SetSpellDescription(
"Consigues influenciar a todos los seres vivos del lugar donde te encuentres\n\
para que se calmen, sean más dóciles y se olviden de sus enemigos.\n");
 }

mixed Check(object caster, string str) {
  object *objs, here;

  here = environment(caster);

  if (!here) return notify_fail("¡No tienes nada alrededor!\n");

  objs = filter(all_inventory(here)-({caster}), SF(living));

  if (!sizeof(objs)) return notify_fail("No hay nada vivo a tu alrededor.\n");

  write("Cierras los ojos e intentas captar con tu mente la energía de los seres vivos que te rodean.\n");
  say(capitalize(caster->QueryName())+" cierra los ojos y se concentra profundamente.\n",({caster}));
  caster->StopAttack(); // El lanzador es el primero q se calma

  return objs;

}

private void _hit(object caster, object contra) {
  write(capitalize((contra->QueryName()||contra->QueryShort()))+" se calma y se tranquiliza.\n");
  tell_object(contra, "Sientes una extraña sensación que te relaja y te calma.\n");

  contra->SetAggressive(0);
  contra->StopAttack();
}

private void _miss(object caster, object contra) {
  write("No consigues calmar a "+capitalize((contra->QueryName()||contra->QueryShort()))+".\n");
  tell_object(contra, "Una extraña sensación intenta relajarte, pero no lo consigue.\n");
}

private void _fumble(object caster, object contra) {
  write("¡Has enfurecido a "+capitalize((contra->QueryName()||contra->QueryShort()))+" aún más!.\n");
  tell_object(contra, "Una extraña sensación intenta relajarte, pero solo consigue enfurecerte.\n");
  contra->DoAttack(caster);
}

//map es un mapping con los objetivos y sus tirada de salvacion
int Cast(object caster, mixed map) {
  play_sound(ENV(caster),SND_MAGIA("calmar.mp3"));

  foreach(object contra, int acierto: map) {
	if (acierto>0) _hit(caster, contra);
	else _miss(caster, contra);
  }

  return 1;
}

// En este conjuro como hay varios objetivos contra deberia ser un array
int Fail(object caster, mixed contra) {
  play_sound(ENV(caster),SND_MAGIA("fallarcalmar.mp3"));

  if (pointerp(contra)) {
    foreach(object o: contra) {
      _fumble(caster, o);
	  }
  }

  return 1;
}
