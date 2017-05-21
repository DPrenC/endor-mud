/* SIMAURIA '/std/magia/mentalismo/luz_cegadora.c'
   ===============================================
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <sounds.h>
#include <effects.h>

inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Luz Cegadora");
  SetSpellUse("contra <objetivo>");
  SetSpellType(ST_LIGHT);
  SetSPCost(15);
  SetCastLevel(GC_KISALAS, 1);
  SetMemorizeLevel(GC_KISALAS, 25);
  SetSaveType(SAVE_TYPE_FORTITUDE);
  SetTiredTime(1);
  SetSpellXP(10);
  SetSpellDescription("\
Emanas una potente luz de tus ojos que ciega a tu adversario momentaneamente.\n");
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
    return notify_fail("¿Quieres cegarte?\n");

  if (caster->Query(P_BLIND))
    return notify_fail("No puedes realizar este hechizo si no puedes ver a tu objetivo.\n");

  if (!CanCastSpell(enemigo)) return 0;

  write("Fijas tu mirada en los ojos de "+enemigo->QueryName()+
    " y concentras todas tus energias en crear una intensa luz.\n");
  say(capitalize(caster->QueryName())+" se concentra y de sus "
    "ojos emana una intensa luz.\n", ({enemigo,caster}));
  tell_object(enemigo,capitalize(caster->QueryName())+" se concentra "
    "y fija su mirada en tus ojos. Una intensa luz aparece en sus ojos.\n");

  return enemigo;
}

private void _hit(object caster, object enemigo) {
  int asaltos;
  object effect;
  int acierto;

  acierto = caster->QueryGuildLevel();
  acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
  if (acierto>100) acierto = 100;

  switch(acierto)
  {
    case   0 .. 25 : asaltos=2; break;
    case  26 .. 50 : asaltos=4; break;
    case  51 .. 75 : asaltos=6; break;
    case  76 ..100 : asaltos=8; break;
    default: asaltos=4;
  }

  seteuid(getuid(TO));

  effect = clone_object(EFFECT_LUZ_CEGADORA);

  effect->SetInitChat("Quedas deslumbrado por "+caster->QueryName()+".\n");
  effect->SetEnvInitChat(capitalize(enemigo->QueryName())+" queda deslumbrado.\n");

  effect->SetEndChat("Dejas de estar deslumbrado por "+caster->QueryName()+".\n");
  effect->SetEnvEndChat(capitalize(enemigo->QueryName())+" deja de estar deslumbrado.\n");

  if (effect->Affect(enemigo, asaltos)) {
    play_sound(ENV(caster),SND_MAGIA("luz_cegadora.mp3"));
  }

  enemigo->Kill(caster);
}

private void _fail(object caster, object enemigo) {

  write("No consigues deslumbrar a "+enemigo->QueryName()+".\n");
  say(capitalize(caster->QueryName())+" no consigue deslumbrar a "+
      enemigo->QueryName()+".\n", ({enemigo,caster}));
  tell_object(enemigo, capitalize(caster->QueryName())+" no consigue deslumbrarte.\n");

}

//map es un mapping con el objetivo y su tirada de salvacion, SOLO deberia
// haber uno, pero como me mola el foreach lo uso.
int Cast(object caster, mixed m) {
  foreach(object contra, int acierto: m) {
    if (acierto>0) _hit(caster, contra);
    else _fail(caster, contra);
  }

  return 1;
}

// En este conjuro como solo hay un objetivo contra deberia ser object
int Fail(object caster, mixed contra) {
  object effect;
  int asaltos, acierto;

  acierto = caster->QueryGuildLevel();
  acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
  if (acierto>100) acierto = 100;

  switch(100-acierto)
  {
    case   0 .. 25 : asaltos=2; break;
    case  26 .. 50 : asaltos=4; break;
    case  51 .. 75 : asaltos=6; break;
    case  76 ..100 : asaltos=8; break;
    default: asaltos=4;
  }

  seteuid(getuid(TO));

  effect = clone_object(EFFECT_LUZ_CEGADORA);

  effect->SetInitChat("Quedas deslumbrado por tu propia luz cegadora.\n");
  effect->SetEnvInitChat(capitalize(caster->QueryName())+" queda deslumbrado por su propia luz.\n");

  effect->SetEndChat("Dejas de estar deslumbrado por tu propia luz cegadora.\n");
  effect->SetEnvEndChat(capitalize(caster->QueryName())+" deja de estar deslumbrado.\n");

  if (effect->Affect(caster, asaltos)) {
    play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  }

  return 1;
}





