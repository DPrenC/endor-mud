/* SIMAURIA '/std/magia/mentalismo/coraza_ligera.c'
   ================================================
   [w] Woo@simauria

   26-11-99 [w] Conjuro de los conjuradores.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())
#define CORAZA   "/guilds/conjuradores/obj/coraza_acero"

create() {
  ::create();
  SetSpellName("Coraza Ligera");
  SetSpellUse("");
  SetSpellType(ST_CREATE);
  SetSPCost(23);
  SetCastLevel(GC_CONJURADORES,5);
  SetMemorizeLevel(GC_CONJURADORES,16);
  SetTiredTime(2);
  SetSpellXP(12);
  SetSpellDescription(
"Creas por un tiempo limitado una coraza de acero mágica que no se degrada\n\
y que permite que los conjuradores la lleven, aunque sea de metal.\n");
 }

int Cast(object caster, mixed mix) {
 int tiempo;
 object coraza;

 tiempo = 30*caster->QueryGuildLevel();

  play_sound(ENV(caster),SND_MAGIA("conjuro.mp3"));
  write("Enlazas las manos de forma firme y gritas unas palabras con voz aguda. "
    "Al instante una reluciente coraza de acero aparece de la nada.\n");

  say(capitalize(caster->QueryName())+" enlaza las manos de forma firme y grita unas "
    "palabras con voz aguda. Una brillante luz ilumina el lugar y ves como "+capitalize(caster->QueryName())+
    " crea una reluciente coraza de acero.\n",caster);

  seteuid(getuid(TO));
  coraza=clone_object(CORAZA);
  coraza->CalcPower(tiempo);
  if(coraza->move(TP) != ME_OK) {
    write("No puedes cargar con la coraza.\n");
    coraza->move(environment(TP),M_DROP);
    return 1;
  }

  return 1;
}


int Fail(object caster, mixed mix) {
  object cosa;

  seteuid(getuid(TO));
  cosa=clone_object("/std/armour");
  cosa->SetQuality(1);
  if(cosa->move(TP) != ME_OK) {
    write("No puedes cargar con "+cosa->QueryShort()+".\n");
    cosa->move(environment(TP),M_DROP);
    return 1;
  }

  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  write(W("Enlazas las manos de forma firme y gritas unas palabras con voz aguda. "
          "Al instante creas "+cosa->QueryShort()+". Crees que algo ha salido mal.\n"));

  say(capitalize(caster->QueryName())+" enlaza las manos de forma firme y grita unas "
        "palabras con voz aguda. Una brillante luz ilumina el lugar y ve como "+capitalize(caster->QueryName())+
        " crea "+cosa->QueryShort()+".\n",caster);

 return 1;
}
