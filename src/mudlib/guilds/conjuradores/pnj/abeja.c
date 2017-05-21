/* SIMAURIA '/guilds/conjuradores/pnj/abeja.c'
   ===========================================
   [w] Woo@simauria
   [h] Nyh@Simauria

   23-03-00 [w] Creación. Este es el bichejo base para el conjuro de enjambre.
   19-06-00 [w] Ahora las abejas son pets..
   18-02-01 [h] Rehago practicamente todo, convirtiendolas en un enjambre
   		de varias abejas, extraido de la hidra. Anulo las funciones
   		de regeneracion de vida y mana, ya que como van a morir en
   		300 segundos no importa mucho, ni se nota ni na.
   27-02-01 [h] Ahora no deja cadaver (espero que no pete)
*/

inherit "/std/npc";
#include <living.h>
#include <properties.h>



object amo;

int abejas, *vida;
static int abejasdelay;

public SetAmo(object obj)	{ return amo=obj;}

int IsFriend(object victim)	{ return (query_once_interactive(victim) || victim == amo ||victim->id("abeja"))?1:0;}

private int SetAbejasDelay(int i) {return abejasdelay=i||0;}
private int QueryAbejasDelay() {return abejasdelay||0;}
private int AddAbejasDelay(int i) {return ((i)?abejasdelay+=i:abejasdelay+=1)||0;}
private int RemoveAbejasDelay(int i) {return ((i)?abejasdelay-=i:abejasdelay-=1)||0;}

public int QueryAbejas()    {return abejas;}
public int SetAbejas(int i) {return abejas=i;}

void AnyadeAbeja(){
  SetAbejas(QueryAbejas()+1);
  vida+=(({QueryMaxHP()}));
  AddHand("aguijón",3,1);
}

void QuitaAbeja(){
  int i;
  SetAbejas(QueryAbejas()-1);
  SetHands(({}));
  for (i=(QueryAbejas()-QueryAbejasDelay());i--;) {AddHand("aguijón",3,1);}
  vida -= ({ 0 });
}

public int SetNumeroAbejas(int i) {
  if (i>0) for (;i--;) {AnyadeAbeja();}
  return i>0?i:0;
}

create() {
  int i;

  vida=(({}));
  ::create();
 SetStandard("una abeja","abeja",random(5)+3,GENDER_FEMALE);
  SetShort("un enjambre de abejas");
  SetLong(W("Es un enjambre de abejas asesinas, son más grandes que las abejas "
  	"normales y tienen un aguijón que asusta a cualquiera.\n"));
  SetIds(({"abeja","abejas","enjambre","enjambre de abejas"}));
  Set(P_IS_PET,1);
  SetAggressive(2);
  call_out("remove",300);
  SetHands(({})); // se ponen luego las abejas

}

int *QueryPV() {return ({QueryHP()})+vida;}

int *AddPV(int i) {
  int c;
  if ((QueryHP()+i)>QueryMaxHP()) SetHP(QueryMaxHP());
  else AddHP(i);
  for(c=1;c<=QueryAbejas();c++)
    { vida[c]=((vida[c]+i)>QueryMaxHP())?QueryMaxHP():(vida[c]+i); }
  return QueryPV();
}

SeePV() {
  int i;
  write("Puntos de vida de las abejas.\n");
  for(i=QueryAbejas();i--;) {write("Abeja "+i+": "+vida[i]+"\n");}
}

public varargs int DoDamage (int dmg, int type, int gentle, mixed xtras) {// a ver a que abeja pega...
  int i;

  i=random(QueryAbejas());
  //QueryPV();
  if ((vida[i]-dmg)<=0) {
    if (sizeof(vida)==1) {
      tell_room(environment(TO),"¡¡El enjambre se desvanece!!\n");
      return ::DoDamage(10000,type,0,xtras);
    }
    vida[i]=0;
    tell_object(TP,"¡¡Has matado una abeja del enjambre!!\n");
    tell_room(environment(TO),"¡¡"+capitalize(TP->QueryName())+" ha matado una abeja del enjambre!!\n",({TP}));
    QuitaAbeja();
    TP->AddXP(QueryKillXP());
    return dmg;
  }
  else {
    vida[i]-=dmg;
    return dmg;
  }
  write("Oooops, error. Avisa a un wiz, mejor el Nyh.\n");
  return ::DoDamage(dmg, type, gentle, xtras);
}

void AnyadeAtaque(int i){
  AddHand("aguijón",3,1);
  RemoveAbejasDelay(1);
}

void QuitaAtaque(int c){
  int i;
  SetHands(({}));
  AddAbejasDelay(1);
  for (i=(QueryAbejas()-QueryAbejasDelay());i--;) {AddHand("aguijón",3,1);}
}

//mixed QueryCombatDelay() { return delaybeats||0;}

public varargs int SetCombatDelay(int i, string s) {
  int x;

  if (i < 1) return 0;
  x=random(QueryAbejas());
  tell_room(environment(TO),"¡Una abeja del enjambre resulta afectada!\n");
  QuitaAtaque(x);
  call_out("AnyadeAtaque",i,x);
  return i;
}

//mixed QueryStunned() { return QueryCombatDelay(); }

mixed SetStunned(int i) {
  int x;

  if (i < 1) return 0;
  x=random(QueryAbejas());
  tell_room(environment(TO),"¡Una abeja del enjambre resulta afectada!\n");
  QuitaAtaque(x);
  call_out("AnyadeAtaque",i,x);
  return i;
}

public varargs void Die(mixed silent) { ::Die(1);}

LeaveCorpse() {return 0;} //haber si asin no deja cuerpo