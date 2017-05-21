#include "../sys/asesinos.h"
#include <herbs.h>

#define COMMAND_NAME	HAB_DO_VENENO
#define MANA_COST	MANA_DO_VENENO

void PasoUno(object ob, object vial);

object empty_vial,
       herb,
       mortar,
       *inv;
int i;

void Destruct(object obj)
{
 if (!obj) return;
 catch(obj->remove());
 if (obj) destruct(obj);
}

int main(string str)
{
   if (TP->HasSkill(COMMAND_NAME) != 1)
      return notify_fail("No tienes la habilidad 'preparar venenos'. Contacta con un wizard.\n");

   if (str != "veneno")
      return notify_fail("¿Preparar qué? ¿Veneno quizás?\n");

   if (TP->Query("_i_am_preparing_poison"))
      return notify_fail("¡Ya estás preparando un veneno!\n");

   inv=all_inventory(TP);
   empty_vial=0;
   herb=0;
   mortar=0;

   for(i=0; i < sizeof(inv); i++)
   {
      if(inv[i]->IsMortar()) mortar=inv[i];
   }
   if(!mortar)
      return notify_fail("No tienes mortero para machacar las hierbas.\n");

   for(i=0; i < sizeof(inv); i++)
   {
      if(inv[i]->IsPoisonVial())
      {
         if(inv[i]->QueryFilled() < 1) empty_vial=inv[i];
      }
   }
   if(!empty_vial)
      return notify_fail("No tienes viales vacíos para poner el veneno.\n");


   dtell("nyh",sprintf("El inventario es:\n"));

   for(i=0; i < sizeof(inv); i++)
   {
      dtell("nyh",sprintf("%O->QueryIsHerb() = %O\t%O\n", inv[i], inv[i]->QueryIsHerb(), inv[i]->QueryClass()));
      if (inv[i]->QueryIsHerb())
      {
         if(inv[i]->QueryClass() == HERB_CLASS_POISONOUS)  herb=inv[i];
      }
   }
   if(!herb)
      return notify_fail("No tienes hierbas venenosas para el preparado.\n");

   tell_object(TP, "Pones las hierbas en el mortero, y empiezas a machacharlas.\n");
   if(TP->QueryInvis() < 1)
      tell_room(environment(TP),TNAME+" pone unas hierbas en un mortero y empieza a machacarlas.\n",({TP}) );
   TP->Set("_i_am_preparing_poison",1);
   herb->move(mortar);
   call_out("PasoUno", 5, herb, empty_vial);
   return 1;
}

void PasoUno(object ob, object vial)
{
int check;

   if(TP->QuerySP() < 10) TP->SetSP(0);
   else TP->AddSP(-10);

   check=(TP->UseSkill(COMMAND_NAME))+(TP->QueryInt());
   if(check > 0)
      call_out("PasoDos",5,ob,vial);
   else
   {
      tell_object(TP,"¡Has cometido un error y no logras extraer veneno suficiente de las hierbas!\n");
      TP->Set("_i_am_preparing_poison",0);
      Destruct(ob);
   }
}

void PasoDos(object ob, object vial)
{
int check;

   tell_object(TP,"Continuas machacando las hierbas...\n");
   if(!TP->QueryInvis())
      tell_room(environment(TP),TNAME+" machaca las hierbas en su mortero.\n",({TP}) );

   if(TP->QuerySP() < 10) TP->SetSP(0);
   else TP->AddSP(-10);

   check=(TP->UseSkill(COMMAND_NAME))+(TP->QueryInt()) -5;
   if(check > 0)
      call_out("PasoTres",5,ob,vial);
   else
   {
      tell_object(TP,"¡Has cometido un error y no logras extraer veneno suficiente de las hierbas!\n");
      TP->Set("_i_am_preparing_poison",0);
      Destruct(ob);
   }
}

void PasoTres(object ob, object vial)
{
int check, power, amount;
string long;
   tell_object(TP,"Terminas de machacar las hierbas en tu mortero.\n");
   if(TP->QueryInvis() < 1)
     tell_room(environment(TP),TNAME+" termina de machacar las hierbas en su mortero.\n",({TP}) );

   if(TP->QuerySP() < 10) TP->SetSP(0);
   else TP->AddSP(-10);

   check=(TP->UseSkill(COMMAND_NAME))+(TP->QueryInt()) - 10;
   if(check > 0)
   {
      amount=check/10;
      if(amount < 1) amount = 1;
      power=ob->QueryPowerNumber();
      vial->SetFilled(amount);
      vial->SetPoisonQuality(check+power);
      tell_object(TP,"Llenas tu vial con el veneno extraído de las hierbas.\n");
      tell_room(environment(TP),TNAME+" llena un vial con un extraño líquido verdoso.\n",({TP}) );
   }
   else
   {
     tell_object(TP,"¡Has derramado el veneno por fuera del vial!\n");
     tell_room(environment(TP),TNAME+" derrama un extraño líquido al intentar llenar un vial "
               "con el contenido de su mortero.\n",({TP}) );
   }
   TP->Set("_i_am_preparing_poison",0);
   Destruct(ob);
}
