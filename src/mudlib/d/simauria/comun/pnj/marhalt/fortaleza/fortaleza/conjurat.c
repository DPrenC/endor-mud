/*=============================================================*
 |             << Fortaleza:Simauria [m] Maler >> 		       |
 *=============================================================*
 |               Creacion............. 06-07-00                |
 |               Ultima Modificacion.. 06-07-00                |
 |                                                             |
 |															   |
 *=============================================================*/
//conjurata
#include "./path.h"
#include <spellmonster.h>
#include <gremios.h>


inherit SPELLMONSTER;
#include <properties.h>
#include <combat.h>
#include <moving.h>
#define ELEMENTAL PNJFF("elementa")
int estad;
public status check_hp();
public int conjurar();
create ()
{
  ::create();
seteuid(getuid());
SetStandard("conjurador","humano",([GC_CONJURADOR: 25+random(5)]),GENERO_MASCULINO);
SetSpellChance(100);
SetWhimpy(0);
SetShort("un conjurador");
SetLong(W("Es un conjurador humano. Viste una larga t�nica multicolor que le tapa la "
"cara. No te haces una idea de si te esta mirando o no, pero parece que tiene malas pulgas.\n"));
SetIds(({"humano","conjurador"}));
SetInt(40);
SetAggressive(1);
SetAlign(-150);
SetSize(P_SIZE_MEDIUM);
InitChats(3,"El conjurador hace unos gestos con las manos.\n");
AddItem(ARMA("vara"),REFRESH_REMOVE,SF(wieldme));
estad=0;
set_heart_beat(1);
AddSpell("conjuros",
([
  S_CHECKFUN:SF(check_hp),
  S_FUN:SF(conjurar),
  S_SP:2,
  S_CHANCE:25,
  S_VICTIMS:1,
  ]));
}

public int check_hp()
{
return QueryHP()<2000;
}

public int conjurar()
{
 object *en,ene,bicho;
 int pupa,mult;
 bicho=TO;
 en=QueryEnemies()||({});
 if(!sizeof(en)) return 0;
 ene=en[random(sizeof(en))];
 if(!ene->QueryIsNpc() && !ene->QueryIsPet())
 {
  switch(random(2))
  {
  case 0:  //lanza//
           pupa=random(20)+1;
           ene->AddHP(-pupa);
           bicho->AddSP(-8);
		   //texto//
           tell_room(environment(),W("El conjurador levanta sus manos hacia el cielo y crea una lanza "
           "de �cido que instant�neamente lanza contra "+ene->QueryName()+".\n"),(({ene})));
           tell_object(ene,W("El conjurador levanta sus manos hacia el cielo y crea una lanza de �cido "
           "que instant�neamente lanza contra ti.\n"));
           return 0; break;
  case 1:  //fr�o//
           bicho->AddSP(-13);
		   ene->SetCombatDelay(random(5)+1,"Est�s congelado.\n");
		   tell_room(environment(),W("El conjurador levanta las manos y se concentras en "+
		   ene->QueryName()+", de pronto un fr�o intenso se apodera del ambiente y ves como "
		   "comienza a congelarse r�pidamente.\n"),(({ene})));
		   tell_object(ene,W("El conjurador levanta las manos y se concentra en t�, de pronto un fr�o intenso "
		   "se apodera del ambiente y ves como comienzas a congelarte r�pidamente.\n"));
		   return 0;break;
   default:return 0;break;
 }
 return 0;
}
return 0;
}
void heart_beat()
{
object *en,ob,ene,bicho;
int pupa,i;
::heart_beat();
en=QueryEnemies()||({});
 if(!sizeof(en)) return 0;
if(living(TO))
{
switch(random(100))
{
case 1..25:if(estad<2)
   {
   tell_room(environment(),W("El conjurador comienza a girar sobre si mismo. De repente se para "
   "en seco y alza las manos hacia el cielo. Un elemental aparece a su lado.\n"));
   TO->AddSP(-53);
   seteuid(getuid());
   ob=clone_object(ELEMENTAL);
   ob->move(environment(TO));
   bicho=TO;
   en=QueryEnemies()||({});
   if(!sizeof(en)) return 0;
   {
   for(i=0;i<sizeof(en);i++)
   {
   en[i]->Kill(ob);
   }
   }
   estad=estad+1;
   }
 return;
 break;
 default:break;
}
}
return;
}
