/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_acidarrow.c
Autor: [T] Tagoras
Fecha: 04/03/2009
Descripcion: Efecto flecha ácida basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Acid Arrow
Conjuration (Creation) [Acid]
Level: 	Sor/Wiz 2
Components: 	V, S, M, F
Casting Time: 	1 standard action
Range: 	Long (400 ft. + 40 ft./level)
Effect: 	One arrow of acid
Duration: 	1 round + 1 round per three levels
Saving Throw: 	None
Spell Resistance: 	No

A magical arrow of acid springs from your hand and speeds to its target. You must succeed on a ranged touch attack to hit your target. The arrow deals 2d4 points of acid damage with no splash damage. For every three caster levels (to a maximum of 18th), the acid, unless somehow neutralized, lasts for another round, dealing another 2d4 points of damage in that round.
Material Component

Powdered rhubarb leaf and an adder.s stomach.
Focus

A dart. 
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <combat.h>
#include <messages.h>
#include <properties.h>
#include <ts.h>

#ifndef COMBATMASTER
#define COMBATMASTER		"/obj/combatmaster"
#endif // COMBATMASTER

#ifndef EFFECTS_DEBUGGER
#define EFFECTS_DEBUGGER	"tagoras"
#endif // EFFECTS_DEBUGGER

inherit ADVANCED_EFFECT;

//------------------------------------------------------------------------------

public string QueryAffectedMessage()
{
	return sprintf("%-30'.'s: %s\n", "Flecha ácida", "Recibes 2d4 de daño ácido durante "+QueryTimeLeft()+" turnos.");
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
		return notify_fail("¿No querrás dispararte una flecha ácida, verdad?\n", NOTIFY_NOT_VALID);
}

public int ExecEffect()
{
	int damage = d4(2);
	string what, how;
	object atk, def;

	damage = QueryAffected()->Defend(damage, TM_ACIDO, /*DEFEND_SPELL |*/ DEFEND_NO_DEF_SK | DEFEND_NOMSG | DEFEND_NOLIV);
	if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
		dtell(EFFECTS_DEBUGGER, sprintf("Daño realizado por acid arrow: %d\n", damage));

	// TODO: Se podrían mejorar los mensajes con el combatmaster
	atk = find_object(QueryCasterName());
	def = QueryAffected();
	COMBATMASTER->GetDamageMessage(damage, &what, &how);
	COMBATMASTER->DoSpellMessage(atk, def, "lanza", "flecha ácida", damage, what, how);
	tell_room(environment(atk), ({MSG_COMBAT, COMBAT_TYPE_SPELL, atk, def, "lanza", "flecha ácida", damage, what, how}), ({atk, def}));

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
	AddId("_acidarrow");
}

//------------------------------------------------------------------------------
