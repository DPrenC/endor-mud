/* SIMAURIA '/std/magia/esencia/hierbas.c'
   =======================================
   [w] Woo@simauria

   14-12-99 [w] Identifica las hierbas y te dice de que tipo son.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <properties.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Identificar Hierba");
  SetSpellUse("<nombre_hierba>");
  SetSpellType(ST_KNOW);
  SetSPCost(10);
  SetCastLevel(GC_CONJURADORES,1);
  SetMemorizeLevel(GC_CONJURADORES,5);
  SetTiredTime(2);
  SetSpellXP(9);
  SetSpellDescription("\
Te permite identificar de que tipo es una determinada hierba.\n");
}

mixed Check(object caster, string args) {
 string quien;
 object hierba;
 
 if (!sizeof(args))
  return notify_fail("¿Qué hierba quieres identificar?\n");

 if (!hierba=present(args,caster))
  return notify_fail("No tienes ninguna hierba llamada "+args+".\n");

 if (member(inherit_list(hierba),"/obj/herb.c")==-1)
  return notify_fail("Hmm.. ¿seguro que eso es una hierba?.\n");

 return hierba;
}

int Cast(object caster, mixed hierba) {

 if (!hierba) return 0;

 write("Concentras tu mirada en "+hierba->QueryShort()+
 " e intentas averiguar que propiedades tiene.\n");
 say(capitalize(caster->QueryName())+" concentra su mirada en "+hierba->QueryShort()+
 ".\n",({caster}));

 write(capitalize(hierba->QueryShort())+" "+(hierba->Query(P_NUMBER)?"son":"es")+
       " de tipo "+hierba->QueryClass()+".\n");

 return 1;
}

int Fail(object caster, mixed hierba) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
 write("Concentras tu mirada en "+hierba->QueryShort()+
 " e intentas averiguar que propiedades tiene.\n");
 say(capitalize(caster->QueryName())+" concentra su mirada en "+hierba->QueryShort()+
 ".\n",({caster}));

 write("No aprecias nada que indique sus propiedades, quizás deberias concentrarte mejor.\n");

 return 1;
}

