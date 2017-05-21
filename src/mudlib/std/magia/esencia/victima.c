
/* SIMAURIA '/std/magia/mentalismo/victima.c'
   ==========================================
   [w] Woo@simauria

   22-11-99 [w] Conjuro de los conjuradores.
   14-02-00 [w] Modificado para que ahora clonee familiares en vez de npcs.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <living.h>
#include <sounds.h>
#include <combat.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())
#define FAMILIAR "/obj/monster/familiar"

create() {
  ::create();
  SetSpellName("Invocar Victima");
  SetSpellUse("");
  SetSpellType(ST_CREATE);
  SetSPCost(16);
  SetCastLevel(GC_CONJURADORES,1);
  SetMemorizeLevel(GC_CONJURADORES,8);
  SetTiredTime(2);
  SetSpellXP(18);
  SetSpellDescription(
"Haces aparecer una víctima en donde te halles con la que poder usar todas tus\n\
habilidades con total impunidad.\n");
 }

int Cast(object caster, mixed mix) {
 object victima;
 int acierto;
 
  write(W("Vas escribiendo con el dedo runas en el suelo. A medida que acabas los trazos se van iluminando formando un círculo de luz.\n"));
  say(W(capitalize(caster->QueryName())+" escribe con el dedo runas en el suelo. A medida que acaba los trazos se van iluminando formando un círculo de luz.\n"),({caster}));

  seteuid(getuid(TO));

  acierto = caster->QueryGuildLevel();
  acierto = random(acierto) + random(acierto) + caster->QueryInt();
  if (acierto>100) acierto = 100;
  
  switch(acierto)
  {
   case   0 .. 10 : victima=clone_object(FAMILIAR);
                    victima->SetStandard("un conejo","conejo",2,GENDER_MALE);
                    break;
   case  11 .. 20 : victima=clone_object(FAMILIAR);
                    victima->SetStandard("una ardilla","ardilla",4,GENDER_FEMALE);
                    break;
   case  21 .. 30 : victima=clone_object(FAMILIAR);
                    victima->SetStandard("un mono","mono",6,GENDER_MALE);
                    break;
   case  31 .. 45 : victima=clone_object(FAMILIAR);
                    victima->SetStandard("un halcón","halcon",8,GENDER_MALE);
                    break;
   case  46 .. 60 : victima=clone_object(FAMILIAR);
                    victima->SetStandard("un cocodrilo","cocodrilo",12,GENDER_MALE);
                    break;
   case  61 .. 75 : victima=clone_object(FAMILIAR);
                    victima->SetStandard("un panda","panda",15,GENDER_MALE);
                    break;
   case  76 .. 90 : victima=clone_object(FAMILIAR);
                    victima->SetStandard("un tigre","tigre",18,GENDER_MALE);
                    break;
   case 91 .. 100 : victima=clone_object(FAMILIAR);
                    victima->SetStandard("un oso","oso",22,GENDER_MALE);
                    break;
   default: victima=clone_object(FAMILIAR);
            victima->SetStandard("un conejo","conejo",1,GENDER_MALE);
  }

  if(victima->move(environment(TP)) != ME_OK)
  {
    write("Algo extraño ocurre y no aparece nada.\n");
    victima->remove();
    return 1;
  }
  seteuid(0);

  tell_room(environment(caster),W("Al instante aparece de la nada "+victima->QueryShort()+" con la mirada perdida.\n"));

  return 1;
}


int Fail(object caster, mixed mix) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  write(W("Vas escribiendo con el dedo runas en el suelo. A medida que acabas los trazos se van iluminando formando un círculo de luz. Inesperadamente el círculo de luz se cierra sobre ti y te provoca un intenso calor.\n"));
  say(W(capitalize(caster->QueryName())+" escribe con el dedo runas en el suelo. A medida que acaba los trazos se van iluminando formando un círculo de luz. Inesperadamente el círculo de luz se cierra sobre "+capitalize(caster->QueryName())+" y lo ves envuelto en llamas.\n"),({caster}));

  caster->Defend(d20(), ST_FIRE, DEFEND_SPELL | DEFEND_NOMSG );

  return 1;
}
