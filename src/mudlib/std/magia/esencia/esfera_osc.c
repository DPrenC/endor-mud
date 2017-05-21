/* SIMAURIA '/std/magia/esencia/esfera_luz.c'
   ==========================================
   [w] Woo@simauria

   23-03-00 [w] Conjuro de los conjuradores.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <living.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())
#define ESFERA   "/guilds/conjuradores/obj/esferao"

create() {
  ::create();
  SetSpellName("Esfera de Oscuridad");
  SetSpellUse("");
  SetSpellType(ST_CREATE);
  SetSPCost(10);
  SetCastLevel(GC_CONJURADORES,1);
  SetMemorizeLevel(GC_CONJURADORES,6);
  SetTiredTime(2);
  SetSpellXP(9);
  SetSpellDescription(
"Creas una esfera de oscuridad que te sigue flotando.\n");
 }

mixed Check(object caster, string arg) {

  write("Extiendes las manos al cielo y te concentras intensamente.\n");
  say(capitalize(caster->QueryName())+" extiende las manos al cielo y se concentra.\n",({caster}));

  return 1;  
}

int Cast(object caster, mixed mix) {
  object esfera;

  seteuid(getuid(TO));

  esfera=clone_object(ESFERA);

  if(esfera->move(environment(TP)) != ME_OK) {
    write("Algo extraño ocurre y no aparece nada.\n");
    esfera->remove();
    return 1;
  }
  caster->AddFollower(esfera);
  seteuid(0);

  tell_room(environment(caster),"Aparece una esfera de oscuridad que se posa encima de tí.\n");

  return 1;
}

int Fail(object caster, mixed mix) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));

  write("Algo ha debido fallar porque tu no ves que haya más oscuridad.\n");

  return 1;
}
