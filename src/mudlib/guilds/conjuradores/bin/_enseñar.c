/* SIMAURIA '/guilds/conjuradores/bin/ense�ar.c'
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
   return notify_fail(" Uso: ense�ar '<nombre_conjuro>' a <jugador>\n"),0;

 if (sscanf(str,"'%s' a %s",conj,jug)!=2)
    return notify_fail(" Uso: ense�ar 'nombre_conjuro' a <jugador>\n"),0;

 if (lower_case(jug) == lower_case(TP->QueryRealName()))
   return notify_fail("�Te intentas ense�ar un conjuro?\n"),0;

 conj = lower_case(conj);
 if (!TP->HasSpell(conj))
   return notify_fail("Primero deberias aprenderlo antes de ense�arselo a alguien, �no crees?\n"),0;

 if (!fichero=SPELL(conj))
   return notify_fail("No conoces ese conjuro.\n"),0;

 sp=TP->QuerySpells();

 if (sp[conj,1]<=50)
   return notify_fail("Deberias memorizar mejor '"+conj+"' antes de intentar ense�arselo a alguien.\n"),0;

 if (!learner=find_object(lower_case(jug)))
   return notify_fail("�Seguro que has visto a esa persona?\n"),0;

 if (environment(learner) != environment(TP))
   return notify_fail("Seria mejor que estuvieras en el mismo lugar que "+capitalize(jug)+".\n"),0;

/* [woo] Por si se quiere que solo ense�en a conjuradores otros conjuradores
 if (learner->QueryGuild() != TP->QueryGuild())
   return notify_fail("Tu gremio no te permite ense�ar nada a gente de otros gremios.\n"),0;
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
 // [w] Como minimo lo aprenderan a 30 de m�ximo.
 if (lspell<30) lspell=30;
 if (lspell>50) lspell=50;

 if (!learner->HasSpell(conj))
 {
   if (learner->AddPlayerSpell(conj,1,lspell,0)<1)
    return notify_fail(capitalize(jug)+" no tiene suficiente nivel para memorizar '"+conj+"'.\n"),0;
 }
  else
   return notify_fail(capitalize(jug)+" ya conoce ese conjuro.\n"),0;

 tell_object(learner,capitalize(TP->QueryRealName())+" te ense�a '"+conj+"'.\n");
 return write("Le ense�as '"+conj+"' a "+capitalize(jug)+".\n"),1;
}
