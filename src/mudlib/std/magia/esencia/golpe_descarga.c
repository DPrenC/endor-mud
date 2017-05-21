
/* SIMAURIA '/std/magia/esencia/golpe_descarga.c'
   ==============================================
   [m] Maler@simauria.upv.es
   20-10-00 [m] hechizo pa conjuratas, el basico nivel 1, creo q pondre el pergamino en la tienda de al lao.
   20-10-00 [m] Chequeo de inteligencia al lanzar y alguna cosilla mas
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <skills.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Golpe de Descarga");
  SetSpellUse("contra <objetivo>");
  SetSpellType(ST_ACID);
  SetSPCost(15);
  SetCastLevel(GC_HECHICEROS,1);
  SetMemorizeLevel(GC_HECHICEROS,1);
  SetTiredTime(1);
  SetSpellXP(13);
  SetSpellDescription("Creas un puño invisible que golpea a tu enemigo.\n");
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

  write("Clavas la vista en tu enemigo y pronuncias las palabras del hechizo pausadamente.\n"
    "Dices: Creil shal dhûl.\n");

  say(capitalize(caster->QueryName())+" clava la vista en "+enemigo->QueryName()+" y pronuncia unas palabras.\n"+
    capitalize(caster->QueryName())+" dice: Creil shal dh–l.\n", ({ enemigo, caster }));

  tell_object(enemigo, capitalize(caster->QueryName())+" clava la vista en ti y pronuncia unas palabras.\n"+
    capitalize(caster->QueryName())+" dice: Creil shal dh–l.\n");

  return enemigo;
}

int Cast(object caster, mixed enemigo) {
  int danyo, acierto;

  acierto = caster->QueryGuildLevel();
  acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
  if (acierto>100) acierto = 100;

  if (acierto<=20)   danyo = caster->QueryInt() + acierto/5;
  else if (acierto<=60)  danyo = caster->QueryInt() + acierto/3;
  else       danyo = caster->QueryInt() + acierto/2;
  if (danyo > (50+caster->QueryInt() ) ) danyo=50+caster->QueryInt();

  play_sound(ENV(caster),SND_MAGIA("golpedescarga.mp3"));
  write(capitalize(enemigo->QueryName())+" retrocede como si hubiese sido golpeado por algo invisible.\n");

  say(capitalize(enemigo->QueryName())+" retrocede como si hubiese sido golpeado por algo invisible.\n"
     , ({ enemigo, caster }));

  tell_object(enemigo, "Al instante notas como algo invisible te golpea.\n");

  enemigo->Kill(caster);
  enemigo->Defend(danyo, TM_APLASTAMIENTO, DEFEND_SPELL);

  return 1;
}


int Fail(object caster, mixed enemigo) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));

  write("Al instante te das cuenta de que te has equivocado con la pronunciación.\n");
  say("Nada pasa.\n", ({ caster }) );

  return 1;
}
