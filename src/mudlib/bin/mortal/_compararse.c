/* Compararse con otro ser
   Yandros, Izet, xx-xx-xx
   Theuzifan, 12-03-99
   Nyh, 02-11-03
*/

#include <properties.h>
#include <gremios.h>
#include <colours.h>
#include "/secure/wizlevels.h"

#define NTF(x) notify_fail(x)

string comparar_stat(object ob, int detail, string stat, string s1, string s2, string s3) {
  int diff, pdiff;
  string mod;


  diff=TP->Query(stat)-ob->Query(stat);
  if (detail<25) {
    if (diff<-5) return(s1+TC_NORMAL);
    if (diff>5) return(s2+TC_NORMAL);
    return("igual de "+s3+TC_NORMAL);
  }
  pdiff=diff;
  if (pdiff<0) pdiff=-pdiff;
  switch (pdiff) {
    case  0..5:  mod="un poco ";	break;
    case  6..10: mod="bastante ";	break;
    case 11..20: mod="mucho ";		break;
    case 21..30: mod="extremadamente "; break;
    default:     mod="infinitamente ";
  }
  if (detail<50) {
    if (diff<0) return(mod+s1+TC_NORMAL);
    if (diff>0) return(mod+s2+TC_NORMAL);
    return("igual de "+s3+TC_NORMAL);
  }
  if (diff<0) return(mod+s1+" ("+(diff>0?"-":"+")+pdiff+")"TC_NORMAL);
  if (diff>0) return(mod+s2+" ("+(diff>0?"-":"+")+pdiff+")"TC_NORMAL);
  return("igual de "+s3+" (="+ob->Query(stat)+")"TC_NORMAL);
}

string comparar_nivel(object ob, int detail) {
  int diff, pdiff;
  string mod;

  if ( !(ob->QueryGuild()) || (ob->QueryGuild())==GC_NINGUNO)
    diff = TP->QueryGuildLevel()- 3*(ob->QueryGuildLevel())/4;
  else
    diff = TP->QueryGuildLevel()-ob->QueryGuildLevel();

// Detalle < 0
  if (detail<0) {
    if (diff<-3) return(TC_RED"Crees que "+capitalize(ob->QueryName())+" es más poderoso que tu.\n");
    if (diff>3)  return(TC_GREEN"Crees que eres más poderoso que "+capitalize(ob->QueryName())+".\n");
    return(TC_YELLOW"Crees que eres más o menos igual de poderoso que "+capitalize(ob->QueryName())+".\n");
  }
// Detalle < 25
  if (detail<25) {
    if (diff<-2) return(TC_RED+capitalize(ob->QueryName())+" es más poderoso que tu.\n");
    if (diff>2)  return(TC_GREEN"Eres más poderoso que "+capitalize(ob->QueryName())+".\n");
    return(TC_YELLOW"Eres más o menos igual de poderoso que "+capitalize(ob->QueryName())+".\n");
  }
// Detalle 25..50
  pdiff=diff;
  if (pdiff<0) pdiff=-pdiff;
  switch (pdiff) {
    case  0..1:  mod="un poco ";	break;
    case  2..5:  mod="bastante ";	break;
    case  6..10: mod="mucho ";		break;
    case 11..20: mod="extremadamente "; break;
    default:     mod="infinitamente ";
  }
  if (detail<50) {
    if (diff<-1) return(TC_RED+capitalize(ob->QueryName())+" es "+mod+"más poderoso"+" que tú.\n");
    if (diff>1) return(TC_GREEN"Eres "+mod+"más poderoso"+" que "+capitalize(ob->QueryName())+".\n");
    return(TC_YELLOW"Eres más o menos igual de poderoso que "+capitalize(ob->QueryName())+".\n");
   }
// Detalle > 50
  if (diff<0) return(TC_RED+capitalize(ob->QueryName())+" es "+mod+"más poderoso"+" ("+(diff>0?"-":"+")+pdiff+")"+" que tú.\n");
  if (diff>0) return(TC_GREEN"Eres "+mod+"más poderoso"+" ("+(diff>0?"-":"+")+pdiff+")"+" que "+capitalize(ob->QueryName())+".\n");
  return(TC_YELLOW"Eres igual de poderoso (="+ob->QueryGuildLevel()+") que "+capitalize(ob->QueryName())+".\n");
}

int main(string quien)
{
  object ob;
  string str2;
  int perc;

  if (!quien) return NTF("¿Compararse con quién?\n");
  sscanf(quien, "con %s", str2);
  if (str2) quien=str2;
  ob=present(quien, environment(TP));

  if (!ob) return NTF(capitalize(quien)+" no está por aqui.\n");
  if (!living(ob) && !ob->Query(P_IS_NPC)) return NTF("No puedes compararte con "+ob->QueryShort()+".\n");
  if (ob==TP) return NTF("Eres... bastante mas estúpid"+(TP->Query(P_GENDER)==GENDER_FEMALE?"a":"o")+" de lo que creías.\n");

  perc=TP->UseSkill("comparar");
//[Nyh] Si, me cargo lo de la habilidad... compara bien siempre, porque la otra
// opcion es que te engañe cuando fallas, y me parece muy gore...
//if (perc>0) {
    if (ob->Query(P_GENDER)==GENDER_FEMALE) {
      write(capitalize(ob->QueryShort())+" es "+
    	comparar_stat(ob, perc, P_STR, "más fuerte", "más debil", "fuerte")+", "+
    	comparar_stat(ob, perc, P_INT, "más inteligente", "menos inteligente", "inteligente")+", "+
      	comparar_stat(ob, perc, P_DEX, "más diestra", "más torpe", "diestra")+" y "+
    	comparar_stat(ob, perc, P_CON, "más fornida", "menos fornida", "fornida")+" que tú.\n");
      write(comparar_nivel(ob,perc)+TC_NORMAL);
    }
    else {
      write(capitalize(ob->QueryShort())+" es "+
    	comparar_stat(ob, perc, P_STR, "más fuerte", "más debil", "fuerte")+", "+
    	comparar_stat(ob, perc, P_INT, "más inteligente", "menos inteligente", "inteligente")+", "+
      	comparar_stat(ob, perc, P_DEX, "más diestro", "más torpe", "diestro")+" y "+
    	comparar_stat(ob, perc, P_CON, "más fornido", "menos fornido", "fornido")+" que tú.\n");
      write(comparar_nivel(ob,perc)+TC_NORMAL);
    }
    return 1;
//}

  return NTF("No consigues compararte con "+ob->QueryShort()+".\n");
}

