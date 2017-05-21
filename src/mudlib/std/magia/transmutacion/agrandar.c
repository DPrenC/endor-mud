/* SIMAURIA '/std/magia/esencia/agrandar.c'
   ========================================
   [w] Woo@simauria
   [Ki] Kintups@simauria
   [t] Tagoras@simauria

   07-04-00 [w] Nuevo conjuro de conjuradores.
   21-11-00 [Ki] Cambiada la fórmula del peso. (4/5) es igual a 0.
   07-03-09 [t] CAmbiado el factor de peso a 5/4, estaba en 3/2
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <skills.h>
#include <sounds.h>

inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

#define DANYO 10

create() {
  ::create();
  SetSpellName("Agrandar Objeto");
  SetSpellUse("<objeto>");
  SetSpellType(ST_CHANGE);
  SetSPCost(25);
  SetCastLevel(GC_CONJURADORES,10);
  SetMemorizeLevel(GC_CONJURADORES,27);
  SetTiredTime(1);
  SetSpellXP(8);
  SetSpellDescription("Agrandas cualquier tipo de objeto.\n");
 }

mixed Check(object caster, string args) {
  string quien;
  object objeto;

  if (!args) return notify_fail("¿Qué objeto quieres agrandar?\n");
  if (!objeto=present(args,caster))
    return notify_fail("No tienes en tu inventario nada que se parezca a eso.\n");
  if (objeto->QueryWeight()==0 || objeto->QuerySize()==P_SIZE_GENERIC)
    return notify_fail("No puedes modificar ese objeto, quizás tenga alguna propiedad mágica.\n");
  if (objeto->QuerySize()>=P_SIZE_HUGE)
    return notify_fail("No puedes modificar ese objeto ya que tiene un tamaño considerable.\n");
  return objeto;
}

int Cast(object caster, mixed objeto) {
  play_sound(ENV(caster),SND_MAGIA("agrandar.mp3"));
  
  write("Pones la mirada en el objeto y extiendes tu mano por encima de él. "
    "El objeto comienza a aumentar de tamaño delante de tus ojos.\n");

  say(capitalize(caster->QueryName())+" pone la mirada fija en un objeto y se concentra. "
    "Comtemplas con asombro como el objeto aumenta de tamaño.\n",({caster}));

  objeto->SetSize(objeto->QuerySize()+1);
  objeto->SetWeight((objeto->QueryWeight()*5)/4);

  return 1;
}


int Fail(object caster, mixed objeto) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  
  write("Pones la mirada en el objeto y extiendes tu mano por encima de él. "
    "Hmmmm... no notas que el tamaño haya aumentado mucho.\n");

  say(capitalize(caster->QueryName())+" pone la mirada fija en un objeto y se concentra, "
    "pero no ves que ocurra nada fuera de lo normal.\n",({caster}));

  if (objeto->QueryArmourType() || objeto->QueryWeaponType()) {
  	write("Parece que has dañado al objeto.\n");
  	objeto->SetQuality(objeto->QueryQuality()-DANYO);
  }

 return 1;
}


