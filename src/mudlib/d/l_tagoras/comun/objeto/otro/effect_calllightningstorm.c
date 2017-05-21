/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_calllightningstorm.c
Autor: [T] Tagoras
Fecha: 08/03/2009
Descripcion: Efecto tormenta de relámpagos basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Call Lightning Storm
Evocation [Electricity]
Level: 	Drd 5
Range: 	Long (400 ft. + 40 ft./level)

This spell functions like call lightning, except that each bolt deals 5d6 points of electricity damage (or 5d10 if created outdoors in a stormy area), and you may call a maximum of 15 bolts. 
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <magia.h>
#include <properties.h>
#include <skills.h>
#include <ts.h>
#include <wizlevels.h>

#define EFFECTS_DEBUGGER	"tagoras"

inherit ADVANCED_EFFECT;

//------------------------------------------------------------------------------

public string QueryAffectedMessage()
{
	return sprintf("%-30'.'s: %s\n", "Tormenta de relámpagos", "Recibes 5d6 (5d10) de daño eléctrico durante "+QueryTimeLeft()+" turnos.");
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
		return notify_fail("¿No querrás acabar en medio de una tormenta de relámpagos, verdad?\n", NOTIFY_NOT_VALID);
}

public int ExecEffect()
{
	int damage;

	if (environment(QueryAffected())->QueryIndoors())
		damage = d6(5);
	else
		// TODO: Se tendría que mirar si el clima es tormentoso
		damage = d10(5);
	// saving throw
	if (SavingThrow())
		damage /= 2;
	damage = QueryAffected()->Defend(damage, TM_ELECTRICIDAD, DEFEND_SPELL | DEFEND_NOMSG | DEFEND_NOLIV);
    if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
        dtell(EFFECTS_DEBUGGER, sprintf("Daño realizado por call lightning storm: %d\n", damage));
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
	AddId("_calllightningstorm");
	SetSaveType(SAVE_TYPE_REFLEX);
}

//------------------------------------------------------------------------------
