/* SIMAURIA '/std/magia/esencia/elemental_fuego.c'
   ===============================================
   [w] Woo@simauria

   16-02-00 [w] Conjuro de los conjuradores.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)    (x->QueryGenderEndString())
#define ELEMENTAL "/obj/monster/elemental"

private object elemental;

create() {
  ::create();
  SetSpellName("Elemental de Fuego");
  SetSpellUse("");
  SetSpellType(ST_CREATE);
  SetSPCost(55);
  SetCastLevel(GC_CONJURADORES,10);
  SetMemorizeLevel(GC_CONJURADORES,25);
  SetTiredTime(5);
  SetSpellXP(10);
  SetSpellDescription(
"Creas un Frirel o Elemental de Fuego que durante un tiempo muy limitado te\n\
seguirá y atacará brutalmente a todos tus enemigos.\n");
 }

mixed Check(object caster, string args) {

  write("Comienzas a girar sobre ti mism"+ART(caster)+" cada vez más deprisa y "
        "alzas los brazos en un golpe seco.\n");
  say(capitalize(caster->QueryName())+" comienza a girar sobre si mism"+ART(caster)+
       " cada vez más deprisa y alza los brazos en un golpe seco.\n");
  
  return 1;
}

int Cast(object caster, mixed mix) {
  seteuid(getuid(TO));

  elemental=clone_object(ELEMENTAL);
  if (elemental->move(environment(caster)) != ME_OK) {
    elemental->remove();
    return 1;
  }

  elemental->SetElemental(caster);

  write("Inmediatamente aparece un Frirel o Elemental de Fuego.\n");
  say("Inmediatamente aparece un Frirel o Elemental de Fuego.\n", ({ caster }) );

  seteuid(0);

  return 1;
}

int Fail(object caster, mixed mix) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  
  write("No ocurre nada anormal y poco a poco vas frenando.\n");
  say("No ocurre nada anormal y poco a poco va frenando.\n", ({ caster }) );

  return 1;
}


