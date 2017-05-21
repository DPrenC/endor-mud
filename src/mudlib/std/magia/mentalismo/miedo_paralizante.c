/* SIMAURIA '/std/magia/mentalismo/miedo_paralizante.c'
   ====================================================
   [w] Woo@simauria

   19-04-99 [w] Hechizo de las kisalas que te provoca un intenso
                miedo por el cual no puedes atacar.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <sounds.h>
#include <effects.h>
#include <properties.h>

inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Miedo Paralizante");
  SetSpellUse("contra <objetivo>");
  SetSpellType(ST_INFLUENCE);
  SetSPCost(20);
  SetCastLevel(GC_GUARDABOSQUES,10);
  SetMemorizeLevel(GC_GUARDABOSQUES,25);
  SetSaveType(SAVE_TYPE_WILL);
  SetTiredTime(1);
  SetSpellXP(14);
  SetSpellDescription("\
Consigues provocar en tu oponente un intenso miedo que le paraliza.\n");
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
    return notify_fail("No creo que hacerse eso sea bueno.\n");

  if (!CanCastSpell(enemigo)) return 0;

  write("Clavas tu mirada en "+enemigo->QueryName()+" y te concentras en sus miedos.\n");
  say(capitalize(caster->QueryName())+" clava su mirada en "+enemigo->QueryName()+".\n", ({caster, enemigo}));
  tell_object(enemigo, capitalize(caster->QueryName())+" clava su mirada en ti.\n");

  return enemigo;
}

private void _hit(object caster, object enemigo) {
  int asaltos, acierto;
  object effect;

  acierto = caster->QueryGuildLevel();
  acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
  if (acierto>100) acierto = 100;

  switch(acierto)
  {
    case   0 .. 25 : asaltos=2; break;
    case  26 .. 50 : asaltos=3; break;
    case  51 .. 75 : asaltos=4; break;
    case 76 .. 100 : asaltos=5; break;
    default: asaltos=2;
  }

  seteuid(getuid(TO));

  effect = clone_object(EFFECT_PARALYZE);

  effect->SetInitChat("Un intenso escalofrio recorre tu cuerpo y el pánico hacia "+caster->QueryName()+" te paraliza.\n");
  effect->SetEnvInitChat(capitalize(enemigo->QueryName())+" comienza a temblar y queda paralizad"+ART(enemigo)+" por miedo hacia "+caster->QueryName()+".\n");

  effect->SetExecChat("Estás paralizad"+ART(enemigo)+" por el miedo hacia "+caster->QueryName()+"\n");

  effect->SetEndChat("Dejas de estar paralizad"+ART(enemigo)+" por miedo a "+caster->QueryName()+".\n");
  effect->SetEnvEndChat(capitalize(enemigo->QueryName())+" deja de estar paralizad"+ART(enemigo)+" de miedo.\n");

  effect->SetSaveDC(QuerySaveDC(caster, enemigo));
  effect->SetSaveType(QuerySaveType());

  if (effect->Affect(enemigo, asaltos)) {
    play_sound(ENV(caster),SND_MAGIA("miedoparalizante.mp3"));
  }

}

private void _miss(object caster, object enemigo) {
  int asaltos;
  int acierto;

  acierto = caster->QueryGuildLevel();
  acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
  if (acierto>100) acierto = 100;
  acierto = 100-acierto;

  switch(-acierto)
  {
    case    0 .. 25 : asaltos=5; break;
    case   26 .. 50 : asaltos=10; break;
    case   51 .. 75 : asaltos=15; break;
    case  76 .. 100 : asaltos=20; break;
    default: asaltos=5;
  }

  play_sound(ENV(caster),SND_MAGIA("fallarmiedo.mp3"));
  write("No consigues encontrar los miedos de "+enemigo->QueryName()+".\n");
  tell_object(enemigo, "Notas como "+capitalize(caster->QueryName())+" intenta "
    "entrar en tu mente y aumentar tu miedo, pero se lo impides.\n");
}

//map es un mapping con el objetivo y su tirada de salvacion, SOLO deberia
// haber uno, pero como me mola el foreach lo uso.
int Cast(object caster, mixed map) {
  foreach(object enemigo, int acierto: map) {
    // Si fallo por 20 o más, pifia
	if (acierto>0) _hit(caster, enemigo);
	else _miss(caster, enemigo);
  }

  return 1;
}

// En este conjuro como solo hay un objetivo enemigo deberia ser object
int Fail(object caster, mixed enemigo) {
  int asaltos;
  int acierto;
  object effect;

  acierto = caster->QueryGuildLevel();
  acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
  if (acierto>100) acierto = 100;
  acierto = 100-acierto;

  switch(-acierto)
  {
    case    0 .. 25 : asaltos=5; break;
    case   26 .. 50 : asaltos=10; break;
    case   51 .. 75 : asaltos=15; break;
    case  76 .. 100 : asaltos=20; break;
    default: asaltos=5;
  }

  seteuid(getuid(TO));

  effect = clone_object(EFFECT_PARALYZE);

  effect->SetInitChat("No consigues concentrarte lo suficiente y el pánico se apodera de ti.\n");
  effect->SetEnvInitChat(capitalize(caster->QueryName())+" empieza a temblar y queda paralizad"+ART(caster)+" por el miedo.\n");

  effect->SetExecChat("Estás paralizad"+ART(caster)+" por tus propios miedos.\n");

  effect->SetEndChat("Dejas de estar paralizad"+ART(caster)+" por tus miedos.\n");
  effect->SetEnvEndChat(capitalize(caster->QueryName())+" deja de estar paralizad"+ART(caster)+" de miedo.\n");

  effect->SetSaveDC(QuerySaveDC(caster, caster));
  effect->SetSaveType(QuerySaveType());

  if (effect->Affect(enemigo, asaltos)) {
    play_sound(ENV(caster),SND_MAGIA("miedoparalizante.mp3"));
  }

  return 1;
}
