/* SIMAURIA '/std/magia/esencia/reducir.c'
   =======================================
   [w] Woo@simauria
   [t] Tagoras@simauria

   07-04-00 [w] Nuevo conjuro de conjuradores.
   21-11-00 [Ki] Cambiado el calculo del peso (5/4) es igual a 1.
                 Cambiado el check(). DEbería ser if (weight<=P_SIZE_SMALL),
                 no (weight>=P_SIZE_SMALL)
   07-03-09 [t] Puesto el factor de peso a 4/5 y hecho que si es
                P_SIZE_GENERIC de el mensaje de propiedad mágica no el muy
                pequeño.
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
  SetSpellName("Reducir Objeto");
  SetSpellUse("<objeto>");
  SetSpellType(ST_CHANGE);
  SetSPCost(25);
  SetCastLevel(GC_CONJURADORES,10);
  SetMemorizeLevel(GC_CONJURADORES,27);
  SetTiredTime(1);
  SetSpellXP(8);
  SetSpellDescription("Reduces cualquier tipo de objeto.\n");
 }

mixed Check(object caster, string args) {
 string quien;
 object objeto;
 
 if (!sizeof(args))
  return notify_fail("¿Qué objeto quieres reducir?\n");

 if (!objeto=present(args,caster))
  return notify_fail("No tienes en tu inventario nada que se parezca a eso.\n");

 if (objeto->QueryWeight()==0 || objeto->QuerySize()==P_SIZE_GENERIC)
  return notify_fail("No puedes modificar ese objeto, quizás tenga alguna propiedad mágica.\n");

 if (objeto->QuerySize()<=P_SIZE_SMALL)
  return notify_fail("No puedes modificar ese objeto, ya es muy pequeño.\n");

 return objeto;
}

int Cast(object caster, mixed objeto) {
  play_sound(ENV(caster),SND_MAGIA("reducir.mp3"));
  
  write("Pones la mirada en el objeto y extiendes tu mano por encima de él. "
    "El objeto comienza a reducir su tamaño delante de tus ojos.\n");

  say(capitalize(caster->QueryName())+" pone la mirada fija en un objeto y se concentra. "
    "Contemplas con asombro como el objeto disminuye de tamaño.\n",({caster}));

  objeto->SetSize(objeto->QuerySize()-1);
  objeto->SetWeight((objeto->QueryWeight()*4)/5);

  return 1;
}

int Fail(object caster, mixed objeto) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  
  write("Pones la mirada en el objeto y extiendes tu mano por encima de él. "
    "Hmmmm... no notas que el tamaño haya disminuido mucho.\n");

  say(capitalize(caster->QueryName())+" pone la mirada fija en un objeto y se concentra, "
    "pero no ves que ocurra nada fuera de lo normal.\n",({caster}));

  if (objeto->QueryArmourType() || objeto->QueryWeaponType())
  {
  	write("Parece que has dañado al objeto.\n");
  	objeto->SetQuality(objeto->QueryQuality()-DANYO);
  }

 return 1;
}


