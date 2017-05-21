/* SIMAURIA '/std/magia/esencia/puerta.c'
   ======================================
   [w] Woo@simauria

   28-03-00 [w] Conjuro general.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <wizlevels.h>
#include <moving.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Puerta Dimensional");
  SetSpellUse("hasta <jugador>");
  SetSpellType(ST_TELEPORT);
  SetSPCost(100);
  SetCastLevel(GC_CONJURADORES,25);
  SetMemorizeLevel(GC_CONJURADORES,35);
  SetTiredTime(2);
  SetSpellXP(25);
  SetSpellDescription("\
Este conjuro te permite crear una puerta dimensional temporal en el lugar\n\
donde te encuentras y otra en donde se encuentre el jugador a traves de\n\
la cual puedes viajar.\n");
}

mixed Check(object caster, string args) {
 string quien;
 object jugador;
 if (!sizeof(args))
   return notify_fail("¿Hasta que jugador quieres ir?\n");

 if (sscanf(args,"hasta %s",quien)!=1)
   return notify_fail("¿Hasta que jugador quieres ir?\n");

 if (!(jugador=find_object(lower_case(quien))) || jugador->Query(P_INVIS))
  return notify_fail(capitalize(quien)+" no está conectado en estos instantes.\n");

 if (jugador==caster)
   return notify_fail("¿Quieres crear dos puertas dimensionales aquí?\n");

 if (jugador && IS_LEARNER(jugador))
   return notify_fail("No puedes ir hasta donde esté un wizard.\n");

 // [w] Para asegurarnos.
 if (!jugador->QueryIsPlayer())
  return notify_fail("Solo puedes crear una puerta en donde esté un jugador.\n");
 if (environment(caster)==environment(jugador))
  return notify_fail("¿Para qué quieres ir al lugar donde ya estás?.\n");

 return jugador;
}

int Cast(object caster, mixed jugador) {
 int mov;
 object antigua;
 string lugar;

  lugar=object_name(environment(jugador));
    if (lugar->Query(P_TPORT)<3)
    {
        play_sound(ENV(caster),SND_MAGIA("forbid.mp3"));
        return write("Una intensa fuerza te ha impedido crear una puerta en ese lugar.\n"),1;
}
    if (environment(caster)->Query(P_TPORT)<3)
    {
        play_sound(ENV(caster),SND_MAGIA("forbid.mp3"));
        return write("Una intensa fuerza te impide que abandones este lugar.\n"),1;
    }

    write(W("Te concentras y te quedas inmóvil con la mirada fija "
   "intentando captar la presencia de "+capitalize(jugador->QueryName())+
   ". Una vez lo has conseguido abres una puerta dimensional.\n"));

  say(W(capitalize(caster->QueryName())+" se concentra y se queda inmóvil con "
   "la mirada fija. Inmediatamente sus ojos toman un color rojo intenso y ves como "
   "empieza a sudar notablemente mientras aparece una puerta dimensional.\n"),({caster}));

  antigua=environment(caster);
  mov=caster->move(environment(jugador),M_SILENT);

  switch(mov) {
  case ME_OK:
   play_sound(ENV(caster),SND_MAGIA("puerta.mp3"));
   tell_room(antigua,capitalize(caster->QueryName())+" atraviesa la puerta y desaparece.\n");
   say("Se abre una puerta dimensional y ves aparecer a "+capitalize(caster->QueryName())+
   ".\n",({caster}));
   tell_room(antigua,"La puerta dimensional se cierra y desaparece.\n");
   return write("Entras en la puerta dimensional y apareces en otro lugar.\n"),1;
  break;
  case ME_NO_LEAVE:
   play_sound(ENV(caster),SND_MAGIA("nopuedes.mp3"));
   tell_room(antigua,"La puerta dimensional se cierra y desaparece.\n");
    return write("No puedes abandonar este lugar.\n"),1;
  break;
  case ME_NO_ENTER:
   play_sound(ENV(caster),SND_MAGIA("nopuedes.mp3"));
   tell_room(antigua,"La puerta dimensional se cierra y desaparece.\n");
    return write("No tienes permiso para ir hasta ese lugar.\n"),1;
  break;
  default:
    play_sound(ENV(caster),SND_MAGIA("nopuedes.mp3"));
    return write("No eres capaz de cruzar la puerta correctamente.\n"),1;
  }

 return 1;
}

int Fail(object caster, mixed jugador) {
  play_sound(ENV(caster),SND_MAGIA("fallarpuerta.mp3"));
  write("Te concentras y te quedas inmóvil con la mirada fija "
   "intentando captar la presencia de "+capitalize(jugador->QueryName())+
   " pero no lo logras.\n");

  say(capitalize(caster->QueryName())+" se concentra y se queda inmóvil con "
   "la mirada fija. Inmediatamente sus ojos toman un color rojo intenso y ves como "
   "empieza a sudar notablemente.\n",({caster}));

 return 1;
}

