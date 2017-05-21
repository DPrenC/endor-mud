/*
DESCRIPCION : bruja
FICHERO     : /d/kenton/comun/quest/bruja/yasmin.c
MODIFICACION: 21-9-00 [Maler] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <living.h>
#include <combat.h>

#include <money.h>
#include <properties.h>
#define HABIT "/d/kenton/comun/quest/bruja/brujahab"
inherit NPC;
mapping list;
string QueryLong()
{
string name;
name=TP->QueryName();
restore_object("/d/kenton/comun/quest/bruja/lista");
if (!list)list=([]);
if(!list[name]){list[name]=(({0,0,0}));}
if(list[name][1]!=1)
		{return "Ves a una anciana elfa de cabellos plateados, mirada penetrante y vivaracha."+
		" Parece mucho m�s anciana de lo que en realidad pudiera ser. No deja de ir de un lado "+
		"a otro y s�lo se detiene al verte entrar para poder observarte un poco mejor.\n"+
		"Aunque seg�n dicen todos es una bruja, sientes seguridad al estar junto a ella, "+
		"no parece ser malvada. Sus ojos te llaman profundamente la atenci�n.\n";}
		else
		{return "Ves a Yasm�n, la madre de Tamara, una elfa noble y gran hechicera, que te sonr�e "+
		"al entrar en su humilde caba�a.\n";
		}
}


init() {

  ::init();
  add_action("dar_cmd","dar");
}
dar_cmd(string str)
{
object from,ob;
int num,*cosa, i, j;
string a, b, name;

j=0;
from=TP;
name=TP->QueryName();
if ((sscanf(str,"%s a yasmin",a)==1)||

		        (sscanf(str,"%s a Yasmin",a)==1)||

		        (sscanf(str,"%s a bruja",a)==1))

		        {

   if (!from || !str) return 0;
         	        ob  =  present(a,TP);

				        if (!ob) return notify_fail("Tu no tienes "+a+".\n",NOTIFY_NOT_VALID)&&0;

if (member(ob->QueryIds(), "quest_lagrima_bruja")!=-1)

		           {

		           ob->remove();
				   restore_object("/d/kenton/comun/quest/bruja/lista");
				   					if (!list)
				   						list=([]);
				   					if (!list[name])
				   						list[name]=({0,0,0});
				   					if(list[name][1]==1){
										write("Yasm�n te dice: Gracias de nuevo.\n");return 1;}
										list[name][1]=1;
									for(i=0;i<sizeof(list[name]);i++)
									{
									if(list[name][i]==1)j+=1;
									if(j==3)
									{
									write(W("Yasm�n te dice: ya lo tengo todo, ahora te transformar� en rana "
									"para que puedas ayudar a Tur�n.\n"));
									HABIT->Guardar_Obs(name);
									restore_object("/d/kenton/comun/quest/bruja/lista");
									list[name]=({0,0,0});
									list[name]=({TP->QueryRace()});
									save_object("/d/kenton/comun/quest/bruja/lista");
									TP->SetFrog(1);
									TP->SetRace("rana_quest");
									RACEMASTER->InitRace(TP,"rana_quest");
									RACEMASTER->AdjustStats(TP);
									write(W("Cuando quieras te devolver� tus objetos "
									"para ello pon retirar.\n"));
									}
									}
				   save_object("/d/kenton/comun/quest/bruja/lista");

		   			write(W("Yasm�n dice: Gracias, gracias por devolverle la felicidad a mi amada hija, pens� que jam�s "
	                   "la recuperar�a. Disc�lpame, mi nombre es Yasm�n, soy la madre de Tamara y hechicera protectora de "
					   "Kl�riton. El tiempo y el dolor hab�an borrado de mi mente toda mi cordura.\nDe nuevo gracias.\n"));
					return 1;
					}


if (member(ob->QueryIds(), "quest_pelo_bruja")!=-1)

		           {

		           ob->remove();
				   restore_object("/d/kenton/comun/quest/bruja/lista");
				   					if (!list)
				   						list=([]);
				   					if (!list[name])
				   						list[name]=({0,0,0});
				   					if(list[name][0]==1){
									write("Yasm�n te dice: Ya me hab�as dado el pelo.\n");return 1;}
										list[name][0]=1;
									for(i=0;i<sizeof(list[name]);i++)
									{
									if(list[name][i]==1)j+=1;
									if(j==3)
									{
									write(W("Yasm�n te dice: ya lo tengo todo, ahora te transformar� en rana "
									"para que puedas ayudar a Tur�n.\n"));
									HABIT->Guardar_Obs(TP->QueryName());
									restore_object("/d/kenton/comun/quest/bruja/lista");
									list[name]=({0,0,0});
									list[name]=({TP->QueryRace()});
									save_object("/d/kenton/comun/quest/bruja/lista");
TP->SetFrog(1);
TP->SetRace("rana_quest");
									RACEMASTER->InitRace(TP,"rana_quest");
									RACEMASTER->AdjustStats(TP);
									write(W("Cuando quieras te devolver� tus objetos "
									"para ello pon retirar.\n"));
									return 1;
									}
									}
				   save_object("/d/kenton/comun/quest/bruja/lista");

		   			write("La bruja dice: Muy bien, ya te falta menos.\n");
					return 1;
					}



if (member(ob->QueryIds(), "quest_flor_bruja")!=-1)

		           {

		           ob->remove();
				   restore_object("/d/kenton/comun/quest/bruja/lista");
				   					if (!list)
				   						list=([]);
				   					if (!list[name])
				   						list[name]=({0,0,0});
				   					if(list[name][2]==1){
									write("Yasm�n te dice: Gracias, pero ya me hab�as dado la flor.\n");return 1;}
										list[name][2]=1;
									for(i=0;i<sizeof(list[name]);i++)
									{
									if(list[name][i]==1)j+=1;
									if(j==3)
									{
									write(W("Yasm�n te dice: ya lo tengo todo, ahora te transformar� en rana "
									"para que puedas ayudar a Tur�n.\n"));
									HABIT->Guardar_Obs(TP->QueryName());
									restore_object("/d/kenton/comun/quest/bruja/lista");
									list[name]=({0,0,0});
									list[name]=({TP->QueryRace()});
									save_object("/d/kenton/comun/quest/bruja/lista");
									TP->SetFrog(1);
									TP->SetRace("rana_quest");
									RACEMASTER->InitRace(TP,"rana_quest");
									RACEMASTER->AdjustStats(TP);
									write(W("Cuando quieras te devolver� tus objetos "
									"para ello pon retirar.\n"));
									return 1;
									}
									}
				   save_object("/d/kenton/comun/quest/bruja/lista");

		   			write("La bruja dice: Muy bien, ya te falta menos.\n");
					return 1;
					}





else
        {
		write("La bruja te dice: Gracias por el regalo.\n");
		return 0;
		}
     }
  return 0;
}


create() {
  ::create();
SetStandard("Yasmin","elfa",30,GENERO_FEMENINO);
AddAdjective("la");
SetIds(({"bruja","yasmin","zorron"}));
SetNoGet("Te vas a follar a tu puta madre.\n");
SetShort("La bruja");
Set(P_CANT_FIGHT,1);
SetLong(W(QueryLong()));
SetAggressive(0); //0 no, 1 si.
SetAlign(100);
}



