/* SIMAURIA '/std/magia/esencia/hogaza.c'
   ======================================
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
#define HOGAZA   "/guilds/conjuradores/obj/hogaza"

create() {
  ::create();
  SetSpellName("Hogaza de Pan");
  SetSpellUse("");
  SetSpellType(ST_CREATE);
  SetSPCost(12);
  SetCastLevel(GC_CONJURADORES,1);
  SetMemorizeLevel(GC_CONJURADORES,8);
  SetTiredTime(2);
  SetSpellXP(10);
  SetSpellDescription(
"Creas una hogaza de pan mágico que te regenerará un poco si te la comes\n");
 }

int Cast(object caster, mixed mix) {
 object hogaza;

  write("Cierras los ojos y te concentras en un poco de comida.. hmm...\n");
  say(capitalize(caster->QueryName())+" cierra los ojos y se concentra.\n",({caster}));

  seteuid(getuid(TO));

  hogaza=clone_object(HOGAZA);

  if(hogaza->move(TP) != ME_OK)
  {
    write("Algo extraño ocurre y no aparece nada.\n");
    hogaza->remove();
    return 1;
  }
  seteuid(0);

  tell_room(environment(caster),"Al instante aparece de la nada una hogaza de pan.\n");
  play_sound(environment(caster), SND_MAGIA("conjuro"));


  return 1;
}


int Fail(object caster, mixed mix) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  write("Cierras los ojos y te concentras en un poco de comida.. hmm... Pero no ocurre nada.\n");
  say(capitalize(caster->QueryName())+" cierra los ojos y se concentra.\n",({caster}));

 return 1;
}
