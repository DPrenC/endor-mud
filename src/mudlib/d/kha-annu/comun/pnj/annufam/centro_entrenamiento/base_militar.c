/**************************************************************************
fichero: base_militar.c
Autor: Tagoras.
Creación: 28/02/2009
Descripción: La base de todos los militares del centro
**************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <nightday.h>

inherit DEFENSOR_BASE_ANNUFAM;

string a_chats(object enemigo);
public void arma();
int ataque(object victima);
public int silent_wieldme(object ob);

public void create()
{
	::create();

	SetAggressive(2);
	SetFriendFunction(SF(ataque));
	InitAChats(4,SF(a_chats));

	AddItem(PROT_CENTRO_ANNUFAM("coraza_guerreros"),REFRESH_REMOVE,SF(wearme));
	AddItem(PROT_CENTRO_ANNUFAM("casco_guerrero"),REFRESH_REMOVE,SF(wearme));
	AddItem(PROT_CENTRO_ANNUFAM("sandalias_soldados"),REFRESH_REMOVE,SF(wearme));
}

string a_chats(object enemigo)
{
	switch(random(3))
	{
		case 0:
			if (QueryHP() > enemigo->QueryHP())
			{
				return W(CAP(QueryName()) + " grita: " +
						 CAP(enemigo->QueryName()) + "! prepárate a "
						 "morir!\n");
			}
			return W(CAP(QueryName()) + " se defiende como puede.\n");
		case 1:
			if (enemigo->QueryRace() == "enano")
			{
				return W(CAP(QueryName()) + " grita: ¡Maldito enano "
						 "traidor!\n");
			}
			return W("El enano grita: ¡Maldit" + ((enemigo->QueryGender() == GENDER_FEMALE)?"a":"o") + " " +
					 enemigo->QueryRace() +"!\n");
		case 2:
			if (QueryMaxHP() == QueryHP()) return "El enano gruñe.\n";
			return "El enano se aqueja de sus heridas.\n";
	}

	return "El enano silba: fiuuuu.\n";
}

int ataque(object victima)
{
	if (member(RAZASENEMIGAS,victima->QueryRace()) >= 0)
	{
		tell_object(victima,W(CAP(TO->QueryName())+ " te grita: Eh, tú, "+
							  victima->QueryRace()+ ", ¿qué haces aquí? ¡Te "
							  "vas a enterar!\n"));
		tell_room(environment(),"El guardia se enfrenta con " +
				  CAP(victima->QueryRealName()) + ".\n",({victima}));
		return 0;
	}
	if (!CheckCAGETraitor(victima))
		return 0;

	return 1;
}

/*
	Equipamos al militar con el arma que toca un segundo despu´s de crearlo para saber qué ha de llevar.
*/
public void arma()
{
	string weapon;

	weapon = environment(TO)->QueryWeapon();
	//tell_room(environment(TO), weapon+"\n");
	//tell_room(environment(TO), TO->QueryIds()[0]+"\n");
	if (weapon)
	{
		if ("ninguna" == weapon)
			return;
		if ("escudo" == weapon)
		{
			AddItem(PROT_CENTRO_ANNUFAM("escudo"), REFRESH_REMOVE, SF(wearme));
			if ("maestro" == TO->QueryIds()[0])
				AddItem(ARMA_CENTRO_ANNUFAM("hacha_oficial"), REFRESH_REMOVE, SF(silent_wieldme));
			else
				AddItem(ARMA_CENTRO_ANNUFAM("hacha_guerreros"), REFRESH_REMOVE, SF(silent_wieldme));
			return;
		}
		if ("espada" == weapon)
		{
			AddItem(ARMA_CENTRO_ANNUFAM("espada"), REFRESH_REMOVE, SF(silent_wieldme));
			if (0==random(2))
				AddItem(ARMA_CENTRO_ANNUFAM("sable"), REFRESH_REMOVE, SF(silent_wieldme));
			return;
		}
		if ("hacha" == weapon)
		{
			if ("maestro" == TO->QueryIds()[0])
				AddItem(ARMA_CENTRO_ANNUFAM("hacha_oficial"), REFRESH_REMOVE, 2, SF(silent_wieldme));
			else
				AddItem(ARMA_CENTRO_ANNUFAM("hacha_guerreros"), REFRESH_REMOVE, 1+random(2), SF(silent_wieldme));
			return;
		}
		AddItem(ARMA_CENTRO_ANNUFAM(environment(TO)->QueryWeapon()), REFRESH_REMOVE, 1+random(2), SF(silent_wieldme));
	}
	else
		if ("maestro" == TO->QueryIds()[0])
			AddItem(ARMA_CENTRO_ANNUFAM("hacha_oficial"), REFRESH_REMOVE, 2, SF(silent_wieldme));
		else
			AddItem(ARMA_CENTRO_ANNUFAM("hacha_guerreros"), REFRESH_REMOVE, 1+random(2), SF(silent_wieldme));
}

public int silent_wieldme(object ob) { return !Equip(ob, ob->QueryWeaponType()?(EWF_WEAPON | EWF_SILENT):(0 | EWF_SILENT)); }
