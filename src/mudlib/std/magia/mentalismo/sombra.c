/* SIMAURIA '/std/magia/mentalismo/sombra.c'
   =========================================
   [w] Woo@simauria

   05-03-00 [w] Conjuro de las kisalas.
   08-03-00 [w] Ahora no llama al SetStandard()
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)    (x->QueryGenderEndString())
#define SOMBRA    "/obj/monster/sombra"

create() {
  ::create();
  SetSpellName("Sombra");
  SetSpellUse("");
  SetSpellType(ST_INFLUENCE);
  SetSPCost(50);
  SetCastLevel(GC_KISALAS,10);
  SetMemorizeLevel(GC_KISALAS,25);
  SetTiredTime(1);
  SetSpellXP(20);
  SetSpellDescription(
"Consigues que tus adversarios crean verte desdoblada como una especie de\n\
sombra de ti misma. Tus ataques resultarán mucho más efectivos.\n");
 }

int Cast(object caster, mixed mix) {
  object sombra;
  if (   (sombra = present("sombra_" + TNREAL, environment(TP)))
      && sombra->QueryIsSombra() && sombra->QueryOwner() == TP)
  {
      return notify_fail("No puedes crear más que una sombra.\n", NOTIFY_NOT_VALID);
  }

  seteuid(getuid(TO));

  sombra=clone_object(SOMBRA);

  if (sombra->move(environment(caster)) != ME_OK)
  {
    sombra->remove();
    return 1;
  }
  sombra->SetOwner(caster);
  play_sound(ENV(caster),SND_MAGIA("sombra.mp3"));
  write("Cierras los ojos e intentas entrar en la mente de la gente que te rodea. Consigues "
      "hacerles creer que junto a ti existe una sombra tuya.\n");
  say(capitalize(caster->QueryName())+" cierra los ojos y de inmediato "
      "ves como.. como.. ¡¡HAY DOS!!.\n",caster);
  seteuid(0);
  return 1;
}


int Fail(object caster, mixed mix)
{
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  write(W("Cierras los ojos e intentas entrar en la mente de la gente que te rodea. No consigues "
          "influenciale en lo más mínimo.\n"));

  say(W(capitalize(caster->QueryName())+" cierra los ojos y los vuelve a abrir, que raro.\n"),({caster}));

 return 1;
}


