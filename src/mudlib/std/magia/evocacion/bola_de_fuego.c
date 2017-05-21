/* SIMAURIA '/std/magia/evocacion/bola_de_fuego.c'
   ==============================================
   [m] Maler@simauria

   20-10-00 [m] creacion.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <skills.h>
#include <combat.h>
#include <sounds.h>
#include <ts.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Bola de Fuego");
  SetSpellUse("");
  SetSpellType(ST_FIRE);
  SetSPCost(25);
  SetCastLevel(GC_HECHICEROS,6);
  SetCastLevel(GC_CONJURADORES,6);
  SetMemorizeLevel(GC_HECHICEROS,12);
  SetMemorizeLevel(GC_CONJURADORES,12);
  SetTiredTime(2);
  SetSpellXP(30);
  SetSaveType(SAVE_TYPE_REFLEX);
  SetSpellDescription(
"Creas una bola de fuego que daña a todos los seres que te rodean.\n"
"Si lo haces en un lugar cerrado puede que no consigas librarte de sus efectos.\n");
 }

mixed Check(object caster, string args) {
  object *objs, here;

  here = environment(caster);

  if (!here) return notify_fail("¡No tienes nada alrededor!\n");

  objs = filter(all_inventory(here)-({caster}), SF(living));

  write("Extiendes la palma de tu mano hacia delante y pronuncias las palabras del hechizo.\n"
  		 "Dices: Creil Ignem Spzereph.\n"
       "Al instante una bola de fuego empieza a crecer rápidamente en la palma de tu mano.\n");

  say(capitalize(caster->QueryName())+" extiende su mano hacia delante y pronuncia unas palabras.\n" +
      capitalize(caster->QueryName())+" dice: Creil Ignem Spzereph.\n"
      "Al instante una bola de fuego empieza a crecer rápidamente en la palma de su mano.\n");

  return objs;
}

//map es un mapping con el objetivo y su tirada de salvacion
int Cast(object caster, mixed map) {
	int j;
  closure fun;

  play_sound(environment(caster), SND_MAGIA("bolafuego.mp3"));

  write("Lanzas la bola de fuego.\n");
  say(capitalize(caster->QueryName()) + " lanza la bola de fuego.\n", ({caster}) );

	j = caster->QueryGuildLevel()/5;
	if (j>10) j = 10;
	j = d6(j);

  foreach(object ob, int acierto: map) {

    //Este if ni idea de q es, supongo q lo habra metido kastwey
    if (   ( ob->Query(P_CANT_FIGHT) & C_MAGIC_FIGHT )
        || (   (fun = ob->QueryChkMagicFunction())
            && !funcall(fun, caster, QuerySpellName()))
       )
    {
      continue;
    }

	  if (acierto>0) ob->Defend(j, TM_CALOR, DEFEND_SPELL);
	  else ob->Defend(j>>1, TM_CALOR, DEFEND_SPELL); // Mitad de daño
  }

  // Si esta indoors el caster hace TS, si la pasa no recibe daño, si falla recibe la mitad
  if (environment(caster)->QueryIndoors()) {
    if (QuerySaveDC(caster, caster) - d20() - caster->QuerySaveBonusType(QuerySaveType()) > 0) {
      write("¡No consigues evitar que la explosión te alcance!");
      caster->Defend(j>>1, TM_CALOR, DEFEND_SPELL); // Mitad de daño
    }
  }

  return 1;
}

int Fail(object caster, mixed mix) {
  play_sound(ENV(caster),SND_MAGIA("fallarbola.mp3"));

  write("¡El fuego te quema!\n");
  say("¡"+capitalize(caster->QueryName())+" se quema la mano con el fuego!\n", ({caster}) );

  caster->Defend(10, DT_FIRE, DEFEND_SPELL);

  return 1;
}
