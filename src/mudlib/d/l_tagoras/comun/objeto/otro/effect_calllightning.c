/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_calllightning.c
Autor: [T] Tagoras
Fecha: 08/03/2009
Descripcion: Efecto relámpago basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Call Lightning
Evocation [Electricity]
Level: 	Drd 3
Components: 	V, S
Casting Time: 	1 round
Range: 	Medium (100 ft. + 10 ft./level)
Effect: 	One or more 30-ft.-long vertical lines of lightning
Duration: 	1 min./level
Saving Throw: 	Reflex half
Spell Resistance: 	Yes

Immediately upon completion of the spell, and once per round thereafter, you may call down a 5-foot-wide, 30-foot-long, vertical bolt of lightning that deals 3d6 points of electricity damage. The bolt of lightning flashes down in a vertical stroke at whatever target point you choose within the spell.s range (measured from your position at the time). Any creature in the target square or in the path of the bolt is affected.

You need not call a bolt of lightning immediately; other actions, even spellcasting, can be performed. However, each round after the first you may use a standard action (concentrating on the spell) to call a bolt. You may call a total number of bolts equal to your caster level (maximum 10 bolts).

If you are outdoors and in a stormy area.a rain shower, clouds and wind, hot and cloudy conditions, or even a tornado (including a whirlwind formed by a djinni or an air elemental of at least Large size).each bolt deals 3d10 points of electricity damage instead of 3d6.

This spell functions indoors or underground but not underwater. 
--------------------------------------------------------------------------------
*/

#include "path.h"

#include <magia.h>
#include <properties.h>
#include <skills.h>
#include <ts.h>
#include <wizlevels.h>

inherit ADVANCED_EFFECT;

#define EFFECTS_DEBUGGER		"tagoras"

//------------------------------------------------------------------------------

public string QueryAffectedMessage()
{
	return sprintf("%-30'.'s: %s\n", "Relámpago", "Recibes 3d6 (3d10) de daño eléctrico durante "+QueryTimeLeft()+" turnos.");
}

//------------------------------------------------------------------------------

public int InitEffect()
{
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	if (present(QueryCasterName(), environment(QueryAffected())) && (QueryCasterName()!=QueryAffected()->QueryRealName())) 
	{
		QueryAffected()->Kill(find_object(QueryCasterName()));
		return ::InitEffect();
	}
	else
		return notify_fail("¿No querrás lanzarte un relámpago, verdad?\n", NOTIFY_NOT_VALID);
}

public int ExecEffect()
{
	int damage;

	if (environment(QueryAffected())->QueryIndoors())
		damage = d6(3);
	else
		// TODO: Se tendría que mirar si el clima es tormentoso
		damage = d10(3);
	// Hay saving throw
	if (SavingThrow())
		damage /= 2;
	damage = QueryAffected()->Defend(damage, TM_ELECTRICIDAD, DEFEND_SPELL | DEFEND_NOMSG | DEFEND_NOLIV);
	if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
 		dtell(EFFECTS_DEBUGGER, sprintf("Daño realizado por call lightning: %d\n", damage));
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
	AddId("_calllightning");
	SetSaveType(SAVE_TYPE_REFLEX);
}

//------------------------------------------------------------------------------
