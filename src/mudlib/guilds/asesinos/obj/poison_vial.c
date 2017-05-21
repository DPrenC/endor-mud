#include "./path.h"
inherit THING;

int poison_amount,
    poison_quality;

int SetFilled(int amount);
int QueryFilled();

int SetPoisonQuality(int quality);
int QueryPoisonQuality();

void
create()
{
   ::create();
  SetAds(({"un","el"}));
   SetShort("un vial");
   SetLong("Es una especie de tubo de ensayo pequeño hecho de cristal.\n");
   SetWeight(100);
   SetFilled(0);
   SetPoisonQuality(0);
   AddId("veneno");
   AddId("veneno_vial");
   AddId("vial");
   SetValue(5000);
}

void
init ()
{
  if(::init()) return;
/*
  add_action("Fill","llenar");
*/
   add_action("Pour","vaciar");
}

int Pour(string str)
{
string *ids;
   ids=QueryIds();
   if(!str && member(ids, str) == -1) return 0;
   else
   {
      SetFilled(0);
      SetPoisonQuality(0);
      write(W("Vacías tu vial en el suelo.\n"));
      say(W(TP->QueryName()+" vacía un tubito con un extraño líquido en el suelo.\n"));
      return 1;
   }
}

int QueryWeight()
{
int extra_weight;
   if(QueryFilled()) extra_weight=10;
   else extra_weight=0;
   return (::QueryWeight()+extra_weight);
}

string QueryShort()
{
string mess;
   mess="";
   SetShort("un vial");
   if(QueryFilled()) mess=" (lleno)";
   else mess=" (vacío)";
   return (::QueryShort()+mess);
}

string QueryLong()
{
string mess;
  mess="";
  SetLong("Es una especie de tubo de ensayo pequeño hecho de cristal.\n");
  if(QueryFilled())
  {
      if(TP->HasSkill("preparar venenos"))
         mess="Esta lleno de veneno, y queda suficiente para "+QueryFilled()+" dosis.\n";
      else
         mess="Esta lleno de un extranyo liquido verdoso.\n";
   }
   else mess="Está vacío.\n";
   return W(::QueryLong()+mess);
}

int SetFilled(int amount)
{
   if(amount < 0) amount=0;
   else if(amount > 1000) amount=1000;
   poison_amount=amount;
   return amount;
}
int QueryFilled() { return poison_amount; }

int SetPoisonQuality(int quality)
{
   if(QueryFilled() < 0) return -1;
   if(quality < 0) quality=0;
   else if(poison_quality > 9999) quality=9999;
   poison_quality=quality;
   return quality;
}
int QueryPoisonQuality() { return poison_quality; }

int IsPoisonVial() { return 1; }
