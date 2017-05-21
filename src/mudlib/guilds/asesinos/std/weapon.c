#include "path.h"
#include <properties.h>
#include <colours.h>
inherit "/std/weapon";
#include "adject.h"

int poison_amount;
object tipo;

int QueryPoisoned();
int SetPoisoned(int amount);

string QueryId()
{
string *ids;
   ids=QueryIds();
   if(!ids) return "ERROR";
   else if(sizeof(ids) < 1) return "ERROR";
   else return(ids[0]);
}

int QueryPoisoned() { return poison_amount; }

int SetPoisoned(int amount)
{
   if(amount < 0) amount=0;
   poison_amount=amount;
   return poison_amount;
}

string QueryLong()
{
string mess;
mess="";
   if(TO->QueryPoisoned())
      mess=capitalize(QueryAdjective())+" "+QueryId()+" ha sido envenenad"+QueryGenero()+".\n";
   else
      mess="";
   return( (::QueryLong())+mess);
}

public varargs void NotifyEquip(object liv, object weapon, int flags)
{
   tipo=liv;
   ::NotifyEquip(liv, weapon, flags);
}

int CalcDamage(object enemy)
{
   if(!enemy) return -1;
   if(!tipo) return -1;
   if(TO->QueryPoisoned() > 0)
   {
      enemy->AddPoison(QueryPoisoned());
      tell_object(enemy,CROJO"¡¡¡ "+tipo->QueryName()+" te ha envenenado !!!\n"CNORMAL);
      tell_object(tipo,CROJO"¡¡¡ Has envenenado a "+enemy->QueryShort()+" !!!\n"CNORMAL);
      SetPoisoned(0);
   }
   return(::CalcDamage());
}

int QueryPoisonable() { return 1; }
