/* SIMAURIA '/std/magia/mentalismo/vision_nocturna.c'
   ==================================================
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
  SetSpellName("Vision Nocturna");
  SetSpellUse("");
  SetSpellType(ST_LIGHT);
  SetSPCost(25);
  SetCastLevel(GC_KISALAS, 1);
  SetMemorizeLevel(GC_KISALAS,12);
  SetTiredTime(2);
  SetSpellXP(10);
  SetSpellDescription("Permite que tus ojos puedan ver en la oscuridad.\n");
}

mixed Check(object caster, string args) {
 write("Cierras los ojos y comienzas a invocar a los "
  "seres de la noche para que te permitan ver como ellos.\n");

 say(capitalize(caster->QueryName())+" cierra los ojos y "
  "comienza a pronunciar una extrañas palabras.\n",({caster}));

 return 1;
}

int Cast(object caster, mixed mix) {
  int tiempo;
  object effect;

  tiempo = 30*caster->QueryGuildLevel();

  seteuid(getuid(TO));
    
  effect = clone_object(EFFECT_VISION_NOCTURNA);
  
  effect->SetInitChat("Sientes un extraño escozor en los ojos y al abrirlos notas "
   "que tu visión ha sufrido una increible transformación.\n");
  effect->SetEnvInitChat(capitalize(caster->QueryName())+" abre los ojos de nuevo y ves "
   "como le brillan en color púrpura.\n");

  effect->SetEndChat("Dejas de poder ver en la oscuridad.\n");
  
  effect->Affect(caster, tiempo);

  return 1;
}

int Fail(object caster, mixed mix) {
/* Quito esto ya que si no no desaparece
 caster->SetSmell(capitalize(caster->QueryName())+
                  " huele como un cadaver descompuesto.\n");
*/

 play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
 write("Pero algo falla y un extraño olor a cadaver descompuesto "
  "te rodea.\n");

 say(capitalize(caster->QueryName())+" abre los ojos de nuevo y notas como "
   "existe un olor horrible en el ambiente.\n",({caster}));

 return 1;
}

