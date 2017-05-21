/***************************************************************************
fichero: defensor_base.c
Autor: kastwey
		[T] Tagoras
Creación: 12/10/2005
Descripción: El guardia, soldado, cadete... todo pnj que implique defender
a un pnj de annufam, ya sea civil o militar.
[T] 18/04/2009: Añadida CheckCAGETraitor para ser usada como friendfunction y atacar a todo aquel que sea un traidor a la legión o el ejército.
***************************************************************************/

#include "./path.h"

inherit PNJ_BASE_ANNUFAM;


public int QueryDefensorAnnufam() { return 1; }

void CompruebaPeleas()
{
	object *inv, *enemigos = ({}), env;
	if (!(env = environment())) return;
	filter(all_inventory(env),(:($1->QueryDefensorAnnufam() && $1 != TO?
								($2 += $1->QueryEnemies() || ({})) : 0):), &enemigos);
	// borramos los elementos repetidos y agregamos los nuevos al enemies.
	SetEnemies(m_indices(mkmapping((QueryEnemies() || ({})) + enemigos)));
}

public varargs int move(mixed dest, int method, mixed extra)
{
	int val = ::move(dest, method, extra);
	CompruebaPeleas();
	return val;
}

public int CheckCAGETraitor(object victim)
{
	if (victim->QueryAttribute(CAGE_TRAITOR))
	{
		tell_object(victim, CAP(QueryShort() + " te mira con odio y grita: Traidor" + (victim->QueryGenderEndString2()) + "!!!\n"));
		tell_room(environment(), CAP(QueryShort() + " mira a " + CAP(victim->QueryName()) + " y le grita: Traidor" + (victim->QueryGenderEndString()) + "!!!\n"), ({victim}));
		return 0;
	}

	return 1;
}

public varargs void Die(mixed silent)
{
	object placas;

	if (QueryKiller() && (!QueryKiller()->QueryAtrribute(CAGE_TRAITOR)) && (placas = present("placas_cage", QueryKiller())))
	{
		//if (find_object("tagoras")) dtell("tagoras", "Estoy en el Die del defensor_base.\n");
		placas->Expell();
	}

	::Die(silent);
}
