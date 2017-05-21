#include "../sys/asesinos.h"

#define COMMAND_NAME	HAB_ENVENENAR
#define MANA_COST	MANA_ENVENENAR

mixed main(string str)
{
int daga, i,check;
object target, poison;
object *arma, *inv;
string *ids;

   arma=TP->QueryWeapons()||({});

   if(sizeof(arma) < 1)
      return notify_fail(W("Tendrás que empuñar el arma que quieras envenenar primero.\n"));
   else if(sizeof(arma) > 1)
      return notify_fail(W("Tendrás que empuñar _sólo_ el arma que quieras envenenar.\n"));
   for(i=0;i<sizeof(arma);i++)
   {
         target=arma[i];
   }
   if(!target)
      return notify_fail(W("ERROR!\n"));
   if(!str)
      return notify_fail(W("Uso:   envenenar <arma>\n"));

   ids=target->QueryIds();
   if(!ids)
      return notify_fail(W("ERROR!\n"));

   if(member(ids, str) == -1)
      return notify_fail(W("No empuñas ningún arma llamada '"+str+"'.\n"));

   if (TP->HasSkill(COMMAND_NAME) != 1)
      return notify_fail(W("No posees la habilidad 'envenenar'. Contacta con un wizard.\n"));

   if(sizeof(TP->QueryEnemies()) )
      return notify_fail(W("¡No puedes envenenar tus armas mientras estás en combate!\n"));

   if(target->QueryPoisoned())
      return notify_fail(W("Tu "+str+" ya tiene veneno.\n"));

   if(NO_MANA(TP))
      return notify_fail(W("No tienes suficientes puntos de magia.\n"));

   poison=present("veneno_vial",TP);
   if(!poison)
      return notify_fail(W("Necesitas el veneno para aplicarlo a tus armas.\n"));

   poison=0;
   inv=deep_inventory(TP);
   for(i=0;i<sizeof(inv);i++)
   {
      if(inv[i]->QueryFilled() > 0) poison=inv[i];
   }

   if(!poison)
      return notify_fail(W("Todos tus tubos de veneno están vacíos.\n"));

   check=TP->UseSkill(COMMAND_NAME);
   if(check <= 0)
   {
      if(TP->QueryInvis() < 1)
         say(W(TP->QueryName()+" hace algo extraño con su "+str+", y la expresión de su cara se torna resignada.\n"));
      poison->SetFilled( (poison->QueryFilled()) - 1);
      return notify_fail(W("No logras envenenar tu "+str+" correctamente.\n"));
   }
   else
   {
      write(W("Pones algo de veneno sobre tu "+str+".\n"));
      if(TP->QueryInvis() < 1)
         say(W(TP->QueryName()+" hace algo extraño con su "+str+", y la expresión de su cara se ilumina.\n"));
      target->SetPoisoned(check + (poison->QueryPoisonQuality()) );
      write(W("El arma tiene un veneno de calidad: "+target->QueryPoisoned()+"\n"));
      poison->SetFilled( (poison->QueryFilled()) - 1);
      return target->QueryPoisoned();
   }
}
