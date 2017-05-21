/**************************************************************************
fichero: soldado_base.c
Autor: Riberales.
		[T] Tagoras
Creación: 7/10/2005
Descripción: La base de todos los soldados de las murallas.
[T] 25/02/2009 Cambiado SERVER_ANNUFAM pro NIGHTDAY para que los soldados ataquen de noche
[T] 18/04/2009: Añadida la comprobación de traidor al CAGE en la friend function
**************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <nightday.h>

inherit DEFENSOR_BASE_ANNUFAM;

string a_chats(object enemigo);
int ataque(object victima);

public int QuerySoldadoMurallasAnnufam() { return 1; }

public void create()
{
	::create();

	SetAggressive(2);
	SetFriendFunction(SF(ataque));
	InitAChats(4,SF(a_chats));
}

string a_chats(object enemigo)
{
	switch(random(3))
	{
		case 0:
			if (QueryHP() > enemigo->QueryHP())
			{
				return W(CAP(QueryName()) + " grita: " + CAP(enemigo->QueryName()) + "! prepárate a morir!\n");
			}
			return W(CAP(QueryName()) + " se defiende como puede.\n");
		case 1:
			if (enemigo->QueryRace() == "enano")
			{
				return W(CAP(QueryName()) + " grita: ¡Maldito enano traidor!\n");
			}
			return W("El enano grita: ¡Maldit" + ((enemigo->QueryGender() == GENDER_FEMALE)?"a":"o") + " " +
					 enemigo->QueryRace() +"!\n");
		case 2:
			if (QueryMaxHP() == QueryHP()) return "El enano gruñe.\n";
			return "El enano se aqueja de sus heridas.\n";
	}

	return "El enano silba: fiuuuuuu.\n";
}

int ataque(object victima)
{
/**/
	//if (member(HORAS_PORTON_CERRADO,SERVER_ANNUFAM->QueryState()) >= 0)
	if (member(HORAS_PORTON_CERRADO,NIGHTDAY->QueryState()) >= 0)
	// el portón está cerrado, así que los soldados atacan a toda persona que
	// esté en las murallas.
	{
		tell_object(victima,CAP(QueryShort()) + " te mira y grita: ");
		tell_room(environment(),"El soldado mira a " +
				  CAP(victima->QueryName()) + " y le grita: ",({victima}));

		tell_room(environment(),"¡" + (victima->QueryGender() == GENDER_MALE ?  "un intruso" : "una intrusa") + "!\n");
	return 0;
	}
/**/

	if (member(RAZASENEMIGAS,victima->QueryRace()) >= 0)
	{
		tell_object(victima,W(CAP(TO->QueryName())+ " te grita: Eh, tú, "+
							  victima->QueryRace()+ ", ¿qué haces aquí? ¡Te vas a enterar!\n"));
		tell_room(environment(),"El guardia se enfrenta con " +
				  CAP(victima->QueryRealName()) + ".\n",({victima}));
		return 0;
	}

	if (!CheckCAGETraitor(victima))
		return 0;

	return 1;
}
