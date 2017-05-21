/***************************************************************************************
 ARCHIVO:	gorgona.c
 AUTOR:		[z] Zomax
 FECHA:		20-11-2001
 COMENTARIOS:	Gorgona del bosque de Cylin
 Última Modificación: Nemesis le cambió el nombre y de paso
                puso algún que otro acento y corrigió algún
		typo que otro.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;
public int parada;

create () {
  ::create();
  SetStandard("Garaleia la Gorgona","gorgona",30,GENERO_FEMENINO);
  SetHands(({({"una garra",1,20}),({"una garra",1,20}),({"una serpiente del pelo",1,15})}));
  SetIds(({"gorgona","Garaleia","garaleia"}));
  SetName("Garaleia");
  SetSize(3);
  SetWhimpy(0);
  SetGoChance(0);
  SetAlign(-500);
  SetHP(500);
  SetMaxHP(500);
  SetSP(500);
  SetMaxSP(500);
  SetStr(40);
  SetInt(20);
  SetCon(30);
  SetDex(30);
  SetAC(10);
  SetAggressive(2);
  SetDesmembrableEn(({RHOEVAR("cylin/cabeza")}));
  SetShort("Garaleia la Gorgona");
  SetLong(W("Esta es Garaleia, la gorgona. Es un monstruo con cuerpo de mujer, "
  	"la cabeza rodeada de serpientes que parece que vayan a saltar hacia ti "
  	"con malas intenciones, dientes puntiagudos como los jabalíes que temes "
  	"que te rocen, escamas en el cuello y alas de oro para volar.\n"));
  AddSubDetail(({"serpiente","serpientes"}),W("Hay montones de serpientes que sales "
  	"de la cabeza de la gorgona. Esperas no tener que acercarte mucho.\n"));
  AddSubDetail(({"cabeza"}),W("Es horrible. Desvías la mirada para no sufrir "
  	"más con esa visión.\n"));
  AddSubDetail(({"diente","dientes"}),W("Más que dientes parecen cuchillos que "
  	"te miran sedientos de sangre y carne.\n"));
  AddSubDetail(({"escama","escamas"}),W("Parecen muy resistentes, quizás sean algún "
  	"tipo de armadura propia.\n"));
  AddSubDetail(({"ala","alas","ala de oro","alas de oro"}),W("Por si no fuera lo "
  	"suficientemente peligrosa parece que puede volar y todo.\n"));

}

Attack()
{
	int j;
	string gen;
	object *enemigos;
	enemigos=QueryEnemies()||({});
	if (sizeof(enemigos) && !random(5))
	{
		for (j=0;j<sizeof(enemigos);j++)
		{
			switch (enemigos[j]->QueryGender())
			{
				case 1: gen="o"; break;
				case 2: gen="a"; break;
				default:gen="o"; break;
			}
			if (present("espejo",enemigos[j]) && present("espejo",enemigos[j])->QueryEquipped() && (present("espejo",enemigos[j])->QueryQuality())>20)
			{
				tell_object(enemigos[j],W("[56mGaraleia abre "
				"los ojos lentamente. Un brillo cegador sale "
				"de ellos directo hacia ti y sin saber como "
				"impacta en el espejo que empuñas. El brillo "
				"se refleja y vuelve hacia ella y le da de lleno. "
				"Parece que se ha paralizado.[0m\n"));
				TO->SetCombatDelay(5,"te conviertes en roca");
				return;
			}
			else
			{
				if (present("espejo",enemigos[j]) && present("espejo",enemigos[j])->QueryEquipped() && (present("espejo",enemigos[j])->QueryQuality())<=25)
				tell_object(enemigos[j],"[57m¡Por todos los dioses, tu espejo está roto.![0m\n");
				tell_object(enemigos[j],W("[56mGaraleia abre los ojos lentamente. "
				"Un brillo cegador sale de ellos directo hacia ti y sientes "
				"como cada centímetro de tu cuerpo se paraliza.[0m\n"));
				switch(enemigos[j]->QueryGender())
				{
 					case 1: enemigos[j]->SetCombatDelay(10,"Estás paralizado.\n");break;
					case 2: enemigos[j]->SetCombatDelay(10,"Estás paralizada.\n");break;
					default:enemigos[j]->SetCombatDelay(10,"Estás paralizado.\n");break;
				}
			}
		}
	}
	return ::Attack();
}

public varargs int SetCombatDelay(int time, string str)
{
	int j;
	if (str=="te conviertes en roca") parada=5;;
	if (parada)	return parada;
	else
	{
		string gen;
		object *enemigos;
		enemigos=QueryEnemies()||({});
		if (sizeof(enemigos))
		{
			for (j=0;j<sizeof(enemigos);j++)
			{
				switch (enemigos[j]->QueryGender())
				{
					case 1: gen="o"; break;
					case 2: gen="a"; break;
					default:gen="o"; break;
				}
				if (present("espejo",enemigos[j]) && present("espejo",enemigos[j])->QueryEquipped() && (present("espejo",enemigos[j])->QueryQuality())>20)
				{
					tell_object(enemigos[j],W("[56mGaraleia abre "
					"los ojos lentamente. Un brillo cegador sale "
					"de ellos directo hacia ti y sin saber como "
					"impacta en el espejo que empuñas. El brillo "
					"se refleja y vuelve hacia ella y le da de lleno. "
					"Parece que se ha paralizado.[0m\n"));
					return parada = 6;
				}
				else
				{
					if (present("espejo",enemigos[j]) && present("espejo",enemigos[j])->QueryEquipped() && (present("espejo",enemigos[j])->QueryQuality())<=25)
					tell_object(enemigos[j],"[57m¡Por todos los dioses, tu espejo está roto.![0m\n");
					tell_object(enemigos[j],W("[56mGaraleia abre los ojos lentamente. "
					"Un brillo cegador sale de ellos directo hacia ti y sientes "
					"como cada centímetro de tu cuerpo se paraliza.[0m\n"));
					switch(enemigos[j]->QueryGender())
					{
 						case 1: enemigos[j]->SetCombatDelay(10,"Estás paralizado.\n");break;
						case 2: enemigos[j]->SetCombatDelay(10,"Estás paralizada.\n");break;
						default:enemigos[j]->SetCombatDelay(10,"Estás paralizado.\n");break;
					}
				}
			}
		}
		return parada=0;
	}
}

public int QueryCombatDelay()	   { return parada; }

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="Bosque de Cylin - Gorgona")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}

public varargs void Die(mixed silent)
{
	if (!TP->QueryIsPlayer() && TP->QueryOwner())
		TP->QueryOwner()->SetAttribute("KillGorgona",1);
	else if(!TP->QueryIsPlayer() && TP->QueryICreator() && (TP->QueryICreator())->QueryIsPlayer())
		TP->QueryICreator()->SetAttribute("KillGorgona",1);
	else if (!TP->QueryAttribute("KillGorgona"))
		TP->SetAttribute("KillGorgona",1);
	::Die(silent);
}
