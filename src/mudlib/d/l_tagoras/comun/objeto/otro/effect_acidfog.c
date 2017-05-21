/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_acidfog.c
Autor: [T] Tagoras
Fecha: 23/04/2009
Descripcion: Efecto niebla ácida basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Acid Fog
Conjuration (Creation) [Acid]
Level: 	Sor/Wiz 6, Water 7
Components: 	V, S, M/DF
Casting Time: 	1 standard action
Range: 	Medium (100 ft. + 10 ft./level)
Effect: 	Fog spreads in 20-ft. radius, 20 ft. high
Duration: 	1 round/level
Saving Throw: 	None
Spell Resistance: 	No

Acid fog creates a billowing mass of misty vapors similar to that produced by a solid fog spell. In addition to slowing creatures down and obscuring sight, this spell.s vapors are highly acidic. Each round on your turn, starting when you cast the spell, the fog deals 2d6 points of acid damage to each creature and object within it.
Arcane Material Component

A pinch of dried, powdered peas combined with powdered animal hoof. 
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <ts.h>

#define EFFECTS_DEBUGGER	"tagoras"

inherit ADVANCED_EFFECT;

//------------------------------------------------------------------------------

public string QueryAffectedMessage()
{
	return sprintf("%-30'.'s: %s\n", "Niebla ácida", "Cada ser vivo y objeto recibe 2d6 de daño ácido durante "+QueryTimeLeft()+" turnos.");
}

//------------------------------------------------------------------------------

public int InitEffect()
{
	object * livs;

	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);

	livs = filter(filter(all_inventory(QueryAffected()), (:living($1):)), (:QueryCasterName() != $1->QueryRealName():));
	if (present(QueryCasterName()))
		foreach(object liv : livs)
			liv->Kill(find_object(QueryCasterName()));

	return ::InitEffect();
}

public int ExecEffect()
{
	int damage = d6(2), done_damage;
	object * livs;
	string * shorts = ({}), msg;

	livs = filter(filter(all_inventory(QueryAffected()), (:living($1):)), (:QueryCasterName() != $1->QueryRealName():));
	foreach(object liv : livs)
	{
		done_damage = liv->Defend(damage, TM_ACIDO, DEFEND_NO_DEF_SK | DEFEND_NOMSG | DEFEND_NOLIV);
		shorts += ({liv->QueryShort()});
		if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
			dtell(EFFECTS_DEBUGGER, sprintf("Daño realizado por acid fog a %s: %d\n", liv->QueryRealName(), done_damage));
	}
	if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
		dtell(EFFECTS_DEBUGGER, sprintf("Shorts [%d] acid fog a %s\n", sizeof(shorts), implode(shorts,", ")));
	
	if (sizeof(shorts))
	{
		msg = "La niebla ácida quema a ";
		if (1 == sizeof(shorts))
			msg += shorts[0]+".\n";
		else
			msg += implode(shorts[..<2], ", a ")+" y a "+shorts[<1]+".\n";
		//SetExecChat(msg);
		//SetEnvExecChat(msg);
		// QueryAffected() es una room, el _say_chat del efecto no funciona en estos casos
		if (QueryAffected())
    		tell_room(QueryAffected(), msg, ({}));

	}
/*
	else
	{
		SetExecChat(0);
		SetEnvExecChat(0);
	}
*/

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
	AddId("_acidfog");
}

//------------------------------------------------------------------------------
