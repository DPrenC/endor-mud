/* SIMAURIA '/std/magia/mentalismo/apocalipsis.c'
   ==============================================
   [w] Woo@simauria
   [m] maler@simauria

   26-10-99 [w] Conjuro de los conjuradores. Puedes provocar hasta 200 puntos
                de daño a todos los seres de la habitación.
   25-11-99 [w] Le he aumentado el LearnLevel hasta 10.
   27-06-03 [m] retocado para adaptar al nuevo sistema de combate.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <combat.h>
#include <sounds.h>
#include <ts.h>

inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Apocalipsis");
  SetSpellUse("");
  SetSpellType(ST_ZAP); // Le meto zap porque engloba varios tipos de daño
  SetSPCost(90);
  SetCastLevel(GC_CONJURADORES,25);
  SetMemorizeLevel(GC_CONJURADORES,35);
  SetTiredTime(2);
  SetSpellXP(30);
  SetSaveType(SAVE_TYPE_REFLEX);
  SetSpellDescription(
"Una lluvia de rayos, fuego, piedras y ácido cae a tu alrededor alcanzando\n\
a todos los seres vivos que te rodeen. Solo si tu nivel de acierto es alto\n\
podrás librarte tu mismo de los efectos. Este conjuro es demasiado potente\n\
para que puedas hacerlo en un lugar cerrado.\n");
 }

mixed Check(object caster, string args) {
  object *objs, here;

  here = environment(caster);

  if (!here) return notify_fail("¡No tienes nada alrededor!\n");

  if (here->QueryIndoors())
    return notify_fail("Será mejor que no hagas un conjuro tan potente en un lugar cerrado.\n");

  objs = filter(all_inventory(here)-({caster}), SF(living));

  write("Miras al cielo y lanzas un poderoso grito al aire. Al instante una enorme "
         "nube llega y se sitúa encima de tu cabeza.\n");
  say(capitalize(caster->QueryName())+" mira al cielo y lanza un poderoso grito al aire."
         " Al instante una enorme nube llega y se sitúa encima de su cabeza.\n");

  return objs;
}

//map es un mapping con el objetivo y su tirada de salvacion
int Cast(object caster, mixed map) {
	int j;
  closure fun;

  play_sound(environment(caster),SND_MAGIA("apocalipsis.mp3"));

  write("Comienza a notarse una ligera "
         "brisa para posteriormente dar paso a una lluvia de rayos, fuego, piedras "
         "y ácido que impacta en todos los seres vivos del lugar.\n");

  say("Comienza a notarse una ligera "
         "brisa para posteriormente dar paso a una lluvia de rayos, fuego, piedras "
         "y ácido que impacta en todos los seres vivos del lugar.\n", ({caster}));

	j = caster->QueryGuildLevel()/5;
	if (j>10) j = 10;
	j = d10(j);

  foreach(object ob, int acierto: map) {

    //Este if ni idea de q es, supongo q lo habra metido kastwey
    if (   ( ob->Query(P_CANT_FIGHT) & C_MAGIC_FIGHT )
        || (   (fun = ob->QueryChkMagicFunction())
            && !funcall(fun, caster, QuerySpellName()))
       )
    {
      continue;
    }

	  if (acierto>0) ob->Defend(j, TM_ELECTRICIDAD, DEFEND_SPELL);
	  else ob->Defend(j>>1, TM_ELECTRICIDAD, DEFEND_SPELL); // Mitad de daño
  }

  return 1;
}

int Fail(object caster, mixed contra) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));

  write("Un enorme rayo cae y te da de lleno.\n");
  say("Un enorme rayo cae y le da de lleno a "+capitalize(caster->QueryName())+".\n", ({caster}));

  caster->Defend(20, TM_ELECTRICIDAD, DEFEND_SPELL);

  return 1;
}


