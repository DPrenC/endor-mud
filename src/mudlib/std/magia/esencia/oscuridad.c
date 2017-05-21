/* SIMAURIA '/std/magia/esencia/oscuridad.c'
   =========================================
   [w] Woo@simauria

   26-10-99 [w] Conjuro de los conjuradores.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())
#define OSC      "/guilds/conjuradores/obj/oscuridad"

create() {
  ::create();
  SetSpellName("Oscuridad");
  SetSpellUse("");
  SetSpellType(ST_LIGHT);
  SetSPCost(10);
  SetCastLevel(GC_CONJURADORES,1);
  SetCastLevel(GC_KISALAS,5);
  SetMemorizeLevel(GC_CONJURADORES,6);
  SetTiredTime(2);
  SetSpellXP(13);
  SetSpellDescription(
"Creas un aura mágica en el lugar que impide que entre la luz.\n");
 }

int Cast(object caster, mixed mix) {
 object o_obj;

  write("Te concentras y una extraña oscuridad se empieza a apoderar del lugar.\n");

  say(capitalize(caster->QueryName())+" se concentra y una extraña oscuridad se empieza a apoderar del lugar.\n"
     , ({caster}));

  seteuid(getuid(TO));
  o_obj=clone_object(OSC);
  if(o_obj->move(environment(TP)) != ME_OK)
  {
    write("Algo falla y la oscuridad desaparece.\n");
    o_obj->remove();
    return 1;
  }

  return 1;
}


int Fail(object caster, mixed mix) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  write(W("Te concentras.. pero algo falla porque todo sigue igual.\n"));

  say(W(capitalize(caster->QueryName())+" se concentra pero no notas nada fuera de lo normal.\n"),({caster}));

 return 1;
}


