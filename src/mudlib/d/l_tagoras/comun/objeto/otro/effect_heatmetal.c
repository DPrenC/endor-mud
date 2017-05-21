/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_heatmetal.c
Autor: [T] Tagoras
Fecha: 08/03/2009
Descripcion: Efecto calentar metal basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Heat Metal
Transmutation [Fire]
Level: 	Drd 2, Sun 2
Components: 	V, S, DF
Casting Time: 	1 standard action
Range: 	Close (25 ft. + 5 ft./2 levels)
Target: 	Metal equipment of one creature per two levels, no two of which can be more than 30 ft. apart; or 25 lb. of metal/level, all of which must be within a 30-ft. circle
Duration: 	7 rounds
Saving Throw: 	Will negates (object)
Spell Resistance: 	Yes (object)

Heat metal makes metal extremely warm. Unattended, nonmagical metal gets no saving throw. Magical metal is allowed a saving throw against the spell. An item in a creature.s possession uses the creature.s saving throw bonus unless its own is higher.

A creature takes fire damage if its equipment is heated. It takes full damage if its armor is affected or if it is holding, touching, wearing, or carrying metal weighing one-fifth of its weight. The creature takes minimum damage (1 point or 2 points; see the table) if it.s not wearing metal armor and the metal that it.s carrying weighs less than one-fifth of its weight.
Round 	Metal
Temperature 	Damage
1 	Warm 	None
2 	Hot 	1d4 points
3-5 	Searing 	2d4 points
6 	Hot 	1d4 points
7 	Warm 	None

On the first round of the spell, the metal becomes warm and uncomfortable to touch but deals no damage. The same effect also occurs on the last round of the spell.s duration. During the second (and also the next-to-last) round, intense heat causes pain and damage. In the third, fourth, and fifth rounds, the metal is searing hot, causing more damage, as shown on the table below.

Any cold intense enough to damage the creature negates fire damage from the spell (and vice versa) on a point-for-point basis. If cast underwater, heat metal deals half damage and boils the surrounding water.

Heat metal counters and dispels chill metal. 
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
	return sprintf("%-30'.'s: %s\n", "Calentar metal", "Tus objetos metálicos se calientan durante "+QueryTimeLeft()+" turnos.");
}

//------------------------------------------------------------------------------

public int InitEffect()
{
	object * items;

	// El caster ha de tener una mano libre
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	// Si el afectado tiene chill metal se quita (lo hacemos antes de comprobar si es a nosotros o a otro para contrarestar)
	if (present("_chillmetal", QueryAffected()))
	{
		present("_chillmetal", QueryAffected())->remove();
		tell_object(QueryAffected(), "El hechizo enfriar metal que te afectaba ha sido contrarestado.\n");
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
			dtell(EFFECTS_DEBUGGER, sprintf("Elementos afectados por heat metal: %O\n", QueryAffectedItems()));
		QueryAffected()->Kill(find_object(QueryCasterName()));

		return ::InitEffect();
	}
	else
		return notify_fail("¿No querrás calentar tus propias pertenencias, verdad?\n", NOTIFY_NOT_VALID);
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
			msg += "templado"+(sizeof(items)==1?"":"s")+".\n";
			msg_env += "templado"+(sizeof(items)==1?"":"s")+".\n";
			break;
		case 2: case 6:
			for (i=0; i < sizeof(items); i++)
				if ((!items[i]->QueryEquipped()) && items[i]->QueryWeigth() < QueryAffected()->QueryWeight()/4)
					damage += 1;
				else
					damage += d4();
			msg += "caliente"+(sizeof(items)==1?"":"s")+".\n";
			msg_env += "caliente"+(sizeof(items)==1?"":"s")+".\n";
			break;
		case 3: case 4: case 5:
			for (i=0; i < sizeof(items); i++)
				if ((!items[i]->QueryEquipped()) && items[i]->QueryWeigth() < QueryAffected()->QueryWeight()/4)
					damage += 2;
				else
					damage += d4(2);
			msg += "abrasando.\n";
			msg_env += "abrasando.\n";
			break;
	}
	SetExecChat(msg);
	SetEnvExecChat(msg_env);
	if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
		dtell(EFFECTS_DEBUGGER, sprintf("Daño realizado por heat metal: %d\n", damage));
	if (damage)
		damage = QueryAffected()->Defend(damage, TM_CALOR, DEFEND_SPELL | DEFEND_NOMSG | DEFEND_NOLIV);
	if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
		dtell(EFFECTS_DEBUGGER, sprintf("Daño realizado por heat metal: %d\n", damage));
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
	AddId("_heatmetal");
	SetSaveType(SAVE_TYPE_WILL);
}

//------------------------------------------------------------------------------
