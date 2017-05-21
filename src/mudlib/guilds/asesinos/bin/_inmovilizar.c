#include "../sys/asesinos.h"

#include <combat.h>
#include <sounds.h>
#include <effects.h>
#include <ts.h>
#include <skills.h>

#define ART(x)   (x->QueryGenderEndString())

#define COMMAND_NAME	HAB_STUN
#define MANA_COST	MANA_STUN
#define TIPO_DE_SALVACION SAVE_TYPE_FORTITUDE

// object: tio q lo usa
// int: nivel del que lo usa
// nada: dc a nivel NIV_STUN_ASESINOS
public varargs int QuerySaveDC(mixed mix) {
  if (objectp(mix)) {
    return 10 + (mix->QueryGuildLevel())/10 + mix->QueryDexModifier();
  }
  if (intp(mix)) {
    return 10 + ((int)mix)/10;
  }
  return 10 + NIV_STUN_ASESINOS/10;
}

mixed main(string str) {
  int check;
  object target, effect;

  if (TP->HasSkill(COMMAND_NAME) != 1)
      return notify_fail("No posees la habilidad "+COMMAND_NAME+".\n");
  if(sizeof(TP->QueryEnemies()))
      return notify_fail("No puedes hacer eso mientras estás en combate!\n");
  if(!str)
      return notify_fail("Inmovilizar a quien?\n");
  if(!target=present(str,environment(TP)))
      return notify_fail("No ves a "+capitalize(str)+" a tu alrededor.\n");
  if(!living(target))
      return notify_fail("Eso ya esta inmóvil!\n");
  if(target==TP)
      return notify_fail("Inmovilizarse a sí mismo es ilógico.\n");
  if(!IS_HUMANOID(target))
      return notify_fail("No puedes inmovilizar criaturas no humanoides.\n");
  if((time()-TP->Query("_last_stun"))<TIMER_INMOVILIZAR)
     return notify_fail("Tendrás que esperar un asaltos para poder volver a inmovilizar.\n");
  if(NO_MANA(TP))
     return notify_fail("No tienes suficientes puntos de magia.\n");
  if (target->Query(P_CANT_FIGHT))
     return notify_fail("No puedes atacar a "+capitalize(str)+".\n");
  if (environment(target)->QuerySafe())
     return notify_fail("No puedes atacar aqui.\n");
  TP->AddSP(-MANA_COST);

  check=TP->UseSkill(COMMAND_NAME, TP->QueryDex()-target->QueryInt())-random(50);

  // Si el asesino falla al atacar o el objetivo supera la tirada de salvación
  if (   check <= 0
      || (d20() + target->QuerySaveBonusType(TIPO_DE_SALVACION) > QuerySaveDC(TP))
      )
   {
      write("Intentas golpear a "+target->QueryName()+" en el cuello "
            "con dos dedos, pero fallas.\n");
      tell_object(target,TP->QueryName()+      " te intenta "
                  "golpear con dos dedos en el cuello, pero falla.\n");
      tell_room(environment(target),TP->QueryName()+
                " intenta golpear a "+target->QueryName()+" en el "
                "cuello con dos dedos, pero falla.\n",({target,TP}));
   }
   else { //if (check > 0) {
     int asaltos;
     switch (check)
     {
         case 1..10:   asaltos = 1; break;
         case 11..24:  asaltos = 2; break;
         case 25..100: asaltos = 3; break;
         default: asaltos = 2; break;
     }

     write("¡Golpeas a "+target->QueryName()+" en el cuello con dos dedos!\n");
     tell_object(target,"¡" + TP->QueryName()+" te golpea en el cuello con dos dedos!\n");
     tell_room(environment(target),TP->QueryName()+" golpea el cuello de "+target->QueryName()+
               " con dos dedos.\n", ({target,TP}) );

     seteuid(getuid(TO));

     effect = clone_object(EFFECT_PARALYZE);

     effect->SetInitChat("¡Quedas inmovilizad"+ART(target)+" por "+TP->QueryName()+"!\n");
     effect->SetEnvInitChat("¡"+capitalize(target->QueryName())+" queda inmovilizad"+ART(target)+"!\n");

     effect->SetExecChat("Continúas inmovilizad"+ART(target)+" por "+TP->QueryName()+"\n");

     effect->SetEndChat("Dejas de estar inmovilizad"+ART(target)+" por "+TP->QueryName()+".\n");
     effect->SetEnvEndChat(capitalize(target->QueryName())+" deja de estar inmovilizad"+ART(target)+".\n");

     effect->SetSaveDC(QuerySaveDC(TP));
     effect->SetSaveType(TIPO_DE_SALVACION);

     if (effect->Affect(target, asaltos)) {
       play_sound(environment(TP), SND_HABILIDADES("inmovilizar"));
     }

   }

   target->Kill(TP);
   TP->Set("_last_stun",time());
   return check || -1;

}
