/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_chillmetal.c
Autor: [T] Tagoras
Fecha: 08/03/2009
Descripcion: Efecto helar metal basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Chill Metal
Transmutation [Cold]
Level: 	Drd 2
Components: 	V, S, DF
Casting Time: 	1 standard action
Range: 	Close (25 ft. + 5 ft./2 levels)
Target: 	Metal equipment of one creature per two levels, no two of which can be more than 30 ft. apart; or 25 lb. of metal/level, none of which can be more than 30 ft. away from any of the rest
Duration: 	7 rounds
Saving Throw: 	Will negates (object)
Spell Resistance: 	Yes (object)

Chill metal makes metal extremely cold. Unattended, nonmagical metal gets no saving throw. Magical metal is allowed a saving throw against the spell. An item in a creature.s possession uses the creature.s saving throw bonus unless its own is higher.

A creature takes cold damage if its equipment is chilled. It takes full damage if its armor is affected or if it is holding, touching, wearing, or carrying metal weighing one-fifth of its weight. The creature takes minimum damage (1 point or 2 points; see the table) if it.s not wearing metal armor and the metal that it.s carrying weighs less than one-fifth of its weight.
Round 	Metal
Temperature 	Damage
1 	Cold 	None
2 	Icy 	1d4 points
3-5 	Freezing 	2d4 points
6 	Icy 	1d4 points
7 	Cold 	None

On the first round of the spell, the metal becomes chilly and uncomfortable to touch but deals no damage. The same effect also occurs on the last round of the spell.s duration. During the second (and also the next-to-last) round, icy coldness causes pain and damage. In the third, fourth, and fifth rounds, the metal is freezing cold, causing more damage, as shown on the table below.

Any heat intense enough to damage the creature negates cold damage from the spell (and vice versa) on a point-for-point basis. Underwater, chill metal deals no damage, but ice immediately forms around the affected metal, making it more buoyant.

Chill metal counters and dispels heat metal. 
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <combat.h>
#include <materials.h>
#include <properties.h>
#include <ts.h>

#define EFFECTS_DEBUGGER	"tagoras"

inherit ADVANCED_EFFECT;

#define METALES ({M_ALUMINIO_TXT, M_PLOMO_TXT, M_HIERRO_TXT, M_ACERO_TXT, M_COBRE_TXT, M_BRONCE_TXT, M_PLATA_TXT, M_ORO_TXT, M_PLATINO_TXT, M_TITANIO_TXT, M_ADAMANTIO_TXT, M_MITHRIL_TXT})

//------------------------------------------------------------------------------

private object * pAffectedItems;

public object * QueryAffectedItems() { return pAffectedItems; }
public object * SetAffectedItems(object * items) { return pAffectedItems=items; }

public string QueryAffectedMessage()
{
	return sprintf("%-30'.'s: %s\n", "Helar metal", "Tus objetos metálicos se enfrían durante "+QueryTimeLeft()+" turnos.");
}

//------------------------------------------------------------------------------

public int InitEffect()
{
	object * items;

	// El caster ha de tener una mano libre
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	// Si el afectado tiene heat metal se quita (lo hacemos antes de comprobar si es anosotros o a otro para contrarestar)
	if (present("_heatmetal", QueryAffected()))
	{
		present("_heatmetal", QueryAffected())->remove();
		tell_object(QueryAffected(), "El hechizo calentar metal que te afectaba ha sido contrarestado.\n");
		return 0;
	}
	// A otro
	if (present(QueryCasterName(), environment(QueryAffected())) && (QueryCasterName()!=QueryAffected()->QueryRealName())) 
	{
		// Los elementos metálicos del affected hasta un máximo del nivel del caster / 2;
		items = filter(deep_inventory(QueryAffected()), (:-1 < member(METALES, $1->QueryMaterial()):))[0..(QueryCasterLevel(1)/2-1)];
		// Los elementos mágicos tienen un saving throw
		items = filter(items, (:!$1->QueryMagic() || !SavingThrow():));
		// No hay elementos metálicos
		if (! sizeof(items))
			return 0;
		SetAffectedItems(items);
		if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
			dtell(EFFECTS_DEBUGGER, sprintf("Elementos afectados por chill metal: %O\n", QueryAffectedItems()));
		QueryAffected()->Kill(find_object(QueryCasterName()));

		return ::InitEffect();
	}
	else
		return notify_fail("¿No querrás enfriar tus propias pertenencias, verdad?\n", NOTIFY_NOT_VALID);
}

public int ExecEffect()
{
	int i, damage;
	string msg, msg_env;
	object * items;

	items = QueryAffectedItems();

	msg = "Tu"+(sizeof(items)==1?"":"s")+" objeto"+(sizeof(items)==1?"":"s")+" está"+(sizeof(items)==1?"":"n")+" ";
	msg_env = (sizeof(items)==1?"El":"los")+" objeto"+(sizeof(items)==1?"":"s")+" de "+CAP(QueryAffected()->QueryRealName())+" está"+(sizeof(items)==1?"":"n")+" ";

	switch (QueryTimeLeft())
	{
		case 1: case 7:
			damage = 0;
			msg += "frío"+(sizeof(items)==1?"":"s")+".\n";
			msg_env += "frío"+(sizeof(items)==1?"":"s")+".\n";
			break;
		case 2: case 6:
			damage = 0;
			for (i=0; i < sizeof(items); i++)
				if ((!items[i]->QueryEquipped()) && items[i]->QueryWeigth() < QueryAffected()->QueryWeight()/4)
					damage += 1;
				else
					damage += d4();
			msg += "helado"+(sizeof(items)==1?"":"s")+".\n";
			msg_env += "helado"+(sizeof(items)==1?"":"s")+".\n";
			break;
		case 3: case 4: case 5:
			damage = 0;
			for (i=0; i < sizeof(items); i++)
				if ((!items[i]->QueryEquipped()) && items[i]->QueryWeigth() < QueryAffected()->QueryWeight()/4)
					damage += 2;
				else
					damage += d4(2);
			msg += "congelado"+(sizeof(items)==1?"":"s")+".\n";
			msg_env += "congelado"+(sizeof(items)==1?"":"s")+".\n";
			break;
	}
	SetExecChat(msg);
	SetEnvExecChat(msg_env);
    if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
        dtell(EFFECTS_DEBUGGER, sprintf("Daño realizado por chill metal: %d\n", damage));
	if (damage)
		damage = QueryAffected()->Defend(damage, TM_FRIO, DEFEND_SPELL | DEFEND_NOMSG | DEFEND_NOLIV);
    if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
        dtell(EFFECTS_DEBUGGER, sprintf("Daño realizado por chill metal: %d\n", damage));
	
	// TODO: Se podrían mejorar los mensajes con el combatmaster

	return ::ExecEffect();
}

/*
public int EndEffect()
{
	QueryAffected()->AddDexBonus(-8);
	return ::EndEffect();
}
*/

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_chillmetal");
	SetSaveType(SAVE_TYPE_WILL);
}

//------------------------------------------------------------------------------
