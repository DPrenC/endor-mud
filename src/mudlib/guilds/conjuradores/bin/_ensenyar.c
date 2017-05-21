/* SIMAURIA '/guilds/conjuradores/bin/enseñar.c'
   =============================================
   [w] Woo@simauria

   23-11-99 [w] Para que puedan aprender conjuros de otros del gremio.
*/

#include <properties.h>
#include <magia.h>

int main( string str )
{
 string jug,conj,fichero;
 object learner;
 int memo_teacher, learn_int, lspell;
 mapping sp;

 seteuid(getuid(TO));
 if (!str)
   return notify_fail(" Uso: enseñar '<nombre_conjuro>' a <jugador>\n"),0;

 if (sscanf(str,"'%s' a %s",conj,jug)!=2)
    return notify_fail(" Uso: enseñar 'nombre_conjuro' a <jugador>\n"),0;

 if (lower_case(jug) == lower_case(TP->QueryRealName()))
   return notify_fail("¿Te intentas enseñar un conjuro?\n"),0;

 conj = lower_case(conj);
 if (!TP->HasSpell(conj))
   return notify_fail("Primero deberias aprenderlo antes de enseñarselo a alguien, ¿no crees?\n"),0;

 if (!fichero=SPELL(conj))
   return notify_fail("No conoces ese conjuro.\n"),0;

 sp=TP->QuerySpells();

 if (sp[conj,1]<=50)
   return notify_fail("Deberias memorizar mejor '"+conj+"' antes de intentar enseñarselo a alguien.\n"),0;

 if (!learner=find_object(lower_case(jug)))
   return notify_fail("¿Seguro que has visto a esa persona?\n"),0;

 if (environment(learner) != environment(TP))
   return notify_fail("Seria mejor que estuvieras en el mismo lugar que "+capitalize(jug)+".\n"),0;

/* [woo] Por si se quiere que solo enseñen a conjuradores otros conjuradores
 if (learner->QueryGuild() != TP->QueryGuild())
   return notify_fail("Tu gremio no te permite enseñar nada a gente de otros gremios.\n"),0;
*/

 if (fichero->QueryMemorizeLevel(learner->QueryGuild())==100)
   return notify_fail(capitalize(jug)+" no puede memorizar ese tipo de magia.\n"),0;

 memo_teacher=sp[conj,0];
 if ((learn_int=learner->QueryInt())>30 && memo_teacher>50)
   lspell = 50;
 else
 {
   lspell=30+(learn_int/5)+(memo_teacher/5);
 }
 // [w] Como minimo lo aprenderan a 30 de máximo.
 if (lspell<30) lspell=30;
 if (lspell>50) lspell=50;

 if (!learner->HasSpell(conj))
 {
   if (learner->AddPlayerSpell(conj,1,lspell,0)<1)
    return notify_fail(capitalize(jug)+" no tiene suficiente nivel para memorizar '"+conj+"'.\n"),0;
 }
  else
   return notify_fail(capitalize(jug)+" ya conoce ese conjuro.\n"),0;

 tell_object(learner,capitalize(TP->QueryRealName())+" te enseña '"+conj+"'.\n");
 return write("Le enseñas '"+conj+"' a "+capitalize(jug)+".\n"),1;
}
