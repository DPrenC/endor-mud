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

inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("teletransporte");
  SetSpellUse("hasta <jugador>");
  SetSpellType(ST_TELEPORT);
  SetSPCost(70);
  SetCastLevel(GC_HECHICEROS,25);
  SetMemorizeLevel(GC_HECHICEROS,35);
  SetTiredTime(3);
  SetSpellXP(25);
  SetSpellDescription("\
Este conjuro te permite teletransportarte hasta otro jugador en el mundo.\n");
}

mixed Check(object caster, string args) {
 string quien;
 object jugador;

 if (!sizeof(args))
   return notify_fail("¿Hasta que jugador quieres ir?\n");

 if (sscanf(args,"hasta %s",quien)!=1)
   return notify_fail("¿Hasta que jugador quieres ir?\n");

 if (   !(jugador=find_object(lower_case(quien)))
     || !(caster->CanSee(jugador)))
  return notify_fail("No encuentras a "+capitalize(quien)+".\n");

 if (jugador==caster)
   return notify_fail("Teletransportarse hasta uno mismo es una estupidez impropia de\n\hechiceros.\n");

 if (jugador && IS_LEARNER(jugador))
   return notify_fail("No puedes ir hasta donde esté un wizard.\n");

 // [w] Para asegurarnos.
 if (!jugador->QueryIsPlayer())
  return notify_fail("Solo puedes teletransportarte hasta un jugador.\n");
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
    return write("Una intensa fuerza te ha impedido teletransportarte hasta ese lugar.\n"),1;

  if (environment(caster)->Query(P_TPORT)<3)
    return write("Una intensa fuerza te impide que abandones este lugar.\n"),1;

  write(W("Te concentras y te quedas inmóvil con la mirada fija "
   "intentando captar la presencia de "+capitalize(jugador->QueryName())+
   ".\n\Dices: Ek'êdaú.\n"));

  say(W(capitalize(caster->QueryName())+" se concentra y se queda inmóvil con "
   "la mirada fija.\n"+capitalize(caster->QueryName())+" dice: Ek'êdaú.\nUn instante "
   "después desaparece.\n"),({caster}));

  antigua=environment(caster);
  mov=caster->move(environment(jugador),M_SILENT);

  switch(mov) {
  case ME_OK:
   tell_room(antigua,capitalize(caster->QueryName())+" se desintegra lentamente.\n");
   say(W("Millones de puntos de colores empiezan a unirse y forman el cuerpo de "+capitalize(caster->QueryName())+
   ".\n"),({caster}));
   return write("Te desintegras lentamente y apareces en otro lugar.\n"),1;
  break;
  case ME_NO_LEAVE:
   tell_room(antigua,"Se desintegra lentamente y rápidamente vuelve a su situación normal.\n");
    return write("No puedes abandonar este lugar.\n"),1;
  break;
  case ME_NO_ENTER:
   tell_room(antigua,"Se desintegra lentamente y rápidamente vuelve a su situación normal.\n");
    return write("No tienes permiso para ir hasta ese lugar.\n"),1;
  break;
  default:
    return write("No eres capaz de teletransportarte correctamente.\n"),1;
  }

 return 1;
}

int Fail(object caster, mixed jugador)
{
  write(W("Te concentras y te quedas inmóvil con la mirada fija "
   "intentando captar la presencia de "+capitalize(jugador->QueryName())+
   " pero no lo logras.\n"));

  say(W(capitalize(caster->QueryName())+" se concentra y se queda inmóvil con "
   "la mirada fija. Inmediatamente sus ojos toman un color rojo intenso y cominza a sudar "
   "notablemente.\n"),({caster}));

 return 1;
}
