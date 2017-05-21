/* SIMAURIA '/std/magia/mentalismo/frio_intenso.c'
 * ===============================================
 */

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <living.h>
#include <sounds.h>
#include <effects.h>
#include <properties.h>

inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Frio Intenso");
  SetSpellUse("contra <objetivo>");
  SetSpellType(ST_COLD);
  SetSPCost(15);
  SetCastLevel(GC_CONJURADORES,1);
  SetMemorizeLevel(GC_CONJURADORES,25);
  SetTiredTime(1);
  SetSpellXP(10);
  SetSaveType(SAVE_TYPE_FORTITUDE);
  SetSpellDescription("\
Congelas a tu enemigo paralizándole por completo.\n");
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

  write("Levantas las manos y te concentras en "+enemigo->QueryName()+".\n");
  say(capitalize(caster->QueryName())+" levanta las manos y se concentra.\n"
     , ({ caster }) );

  return enemigo;
}

private void _miss(object caster, object enemigo) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));

  write("Un frío intenso se apodera de "+enemigo->QueryName()+", pero parece no afectarle.\n");
  say("Un frío intenso se apodera de "+enemigo->QueryName()+", pero parece no afectarle.\n"
     , ({enemigo,caster}));
  tell_object(enemigo, "Un frío intenso intenta apoderase de ti, pero no lo consigue.\n");
}

private void _hit(object caster, object enemigo) {
 int i, asaltos;
 int acierto;
 object effect;

	acierto = caster->QueryGuildLevel();
	acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
	if (acierto>100) acierto = 100;

 i = (caster->QueryGuildLevel()+caster->QueryInt())/15;
 asaltos = i+acierto/25;

 //if (find_object("nyh")) dtell("nyh",sprintf("[%i] %O enfrio a [%i]%O: base: %i, mod: %i, total: %i",
 	//caster->QueryGuildLevel(),caster->QueryName(),enemigo->QueryLevel(),enemigo->QueryName(),i,asaltos-i,asaltos ));
 asaltos = asaltos*(100-enemigo->QueryResistance("frio intenso"))/100;
 asaltos = asaltos*(100-enemigo->QueryResistance(TM_FRIO))/100;
// if (find_object("nyh")) dtell("nyh",sprintf(", final: %i\n",asaltos ));

 if (asaltos > 0) {
   seteuid(getuid(TO));

   effect = clone_object(EFFECT_PARALYZE);

   effect->SetInitChat("Un frío intenso se apodera de ti y notas como tus miembros comienzan a congelarse.\n");
   effect->SetEnvInitChat("Un frio intenso se apodera de "+enemigo->QueryName()+" y ves como comienza a congelarse.\n");

   effect->SetExecChat("Estás congelad"+ART(enemigo)+" por "+caster->QueryName()+"\n");

   effect->SetEndChat("Dejas de estar paralizad"+ART(enemigo)+" por "+caster->QueryName()+".\n");
   effect->SetEnvEndChat(capitalize(enemigo->QueryName())+" deja de estar congelad"+ART(enemigo)+".\n");

   effect->SetSaveDC(QuerySaveDC(caster, enemigo));
   effect->SetSaveType(QuerySaveType());

   if (effect->Affect(enemigo, asaltos)) {
     play_sound(ENV(caster),SND_MAGIA("conjuro.mp3"));
   }
 }
 else {
   _miss(caster, enemigo);
 }

}

//map es un mapping con el objetivo y su tirada de salvacion, SOLO deberia
// haber uno, pero como me mola el foreach lo uso.
int Cast(object caster, mixed map) {
  foreach(object contra, int acierto: map) {
    contra->Kill(caster);
	  if (acierto>0) _hit(caster, contra);
	  else _miss(caster, contra);
  }

  return 1;
}

// En este conjuro como solo hay un objetivo contra deberia ser object
int Fail(object caster, mixed contra) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  contra->Kill(caster);

  write("Levantas las manos y te concentras en "+contra->QueryName()+
    ", de pronto un frio intenso recorre el lugar pero fallas y comienza a "
    "granizar.\n");

	say(capitalize(caster->QueryName())+" levanta las manos y se concentra, de pronto "
  "un frio intenso recorre el ambiente y comienza a granizar bastante fuerte.\n",({caster}));

  return 1;
}


