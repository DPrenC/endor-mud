/* SIMAURIA '/std/magia/esencia/enjambre.c'
   ========================================
   [w] Woo@simauria
   [h] Nyh@Simauria
   23-03-00 [w] Conjuro de los conjuradores.
   05-04-00 [w] Separados los for, para evitar los too long evaluation.
   17-02-01 [h] Adaptado a el nuevo enjambre de abejas
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <living.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())
#define ABEJA    "/guilds/conjuradores/pnj/abeja"

create() {
    ::create();
    SetSpellName("Enjambre");
    SetSpellUse("");
    SetSpellType(ST_CREATE);
    SetSPCost(20);
    SetCastLevel(GC_CONJURADORES,1);
    SetMemorizeLevel(GC_CONJURADORES,5);
    SetTiredTime(4);
    SetSpellXP(10);
    SetSpellDescription("Haces aparecer un enjambre de abejas que atacan a todo lo que haya en "
        "la habitación, a excepción de ti.\n");
}

int Cast(object caster, mixed mix) {
  object abeja;
	int acierto;
    
	write("Te concentras e invocas un enjambre de abejas.\n");
  say(capitalize(caster->QueryName())+" se concentra y pronuncia unas palabras.\n",caster);
  seteuid(getuid(TO));
  abeja=clone_object(ABEJA);
  abeja->SetAmo(caster);

	acierto = caster->QueryGuildLevel();
	acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
	if (acierto>100) acierto = 100;	
	
  switch(acierto)
  {
      case  0..25:  abeja->SetNumeroAbejas(4); break;
      case 26..50:  abeja->SetNumeroAbejas(5); break;
      case 51..75:  abeja->SetNumeroAbejas(6); break;
      case 76..100: abeja->SetNumeroAbejas(8); break;
      default: abeja->SetNumeroAbejas(4); break;
  }
  if(abeja->move(environment(TP)) != ME_OK) abeja->remove();
  seteuid(0);
  play_sound(environment(caster),SND_MAGIA("enjambre.mp3"));
  tell_room(environment(caster),"Aparece un enjambre lleno de abejas asesinas.\n");
  
  return 1;
}


int Fail(object caster, mixed mix) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  write(W("Te concentras e invocas un enjambre de abejas asesinas.\n"));
  say(W(capitalize(caster->QueryName())+" se concentra y pronuncia unas palabras.\n"),({caster}));
  write("Parece que las abejas no te reconocen, has debido fallar en algo.\n");
  return 1;
}
