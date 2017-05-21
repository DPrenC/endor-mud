/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_wounds.c
Autor: [T] Tagoras
Fecha: 04/03/2009
Descripcion: Efecto curar o infligir heridas basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Cure Light Wounds
Conjuration (Healing)
Level: 	Brd 1, Clr 1, Drd 1, Healing 1, Pal 1, Rgr 2
Components: 	V, S
Casting Time: 	1 standard action
Range: 	Touch
Target: 	Creature touched
Duration: 	Instantaneous
Saving Throw: 	Will half (harmless); see text
Spell Resistance: 	Yes (harmless); see text

When laying your hand upon a living creature, you channel positive energy that cures 1d8 points of damage +1 point per caster level (maximum +5).

Since undead are powered by negative energy, this spell deals damage to them instead of curing their wounds. An undead creature can apply spell resistance, and can attempt a Will save to take half damage. 
--------------------------------------------------------------------------------
Cure Moderate Wounds
Conjuration (Healing)
Level: 	Brd 2, Clr 2, Drd 3, Healing 2, Pal 3, Rgr 3

This spell functions like cure light wounds, except that it cures 2d8 points of damage +1 point per caster level (maximum +10). 
--------------------------------------------------------------------------------
Cure Serious Wounds
Conjuration (Healing)
Level: 	Brd 3, Clr 3, Drd 4, Pal 4, Rgr 4, Healing 3

This spell functions like cure light wounds, except that it cures 3d8 points of damage +1 point per caster level (maximum +15). 
--------------------------------------------------------------------------------
Cure Critical Wounds
Conjuration (Healing)
Level: 	Brd 4, Clr 4, Drd 5, Healing 4

This spell functions like cure light wounds, except that it cures 4d8 points of damage +1 point per caster level (maximum +20). 
--------------------------------------------------------------------------------
Inflict Light Wounds
Necromancy
Level: 	Clr 1, Destruction 1
Components: 	V, S
Casting Time: 	1 standard action
Range: 	Touch
Target: 	Creature touched
Duration: 	Instantaneous
Saving Throw: 	Will half
Spell Resistance: 	Yes

When laying your hand upon a creature, you channel negative energy that deals 1d8 points of damage +1 point per caster level (maximum +5).

Since undead are powered by negative energy, this spell cures such a creature of a like amount of damage, rather than harming it. 
--------------------------------------------------------------------------------
Inflict Moderate Wounds
Necromancy
Level: 	Clr 2

This spell functions like inflict light wounds, except that you deal 2d8 points of damage +1 point per caster level (maximum +10). 
--------------------------------------------------------------------------------
Inflict Serious Wounds
Necromancy
Level: 	Clr 3

This spell functions like inflict light wounds, except that you deal 3d8 points of damage +1 point per caster level (maximum +15). 
--------------------------------------------------------------------------------
Inflict Critical Wounds
Necromancy
Level: 	Clr 4, Destruction 4

This spell functions like inflict light wounds, except that you deal 4d8 points of damage +1 point per caster level (maximum +20). 
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <ts.h>
#include <wizlevels.h>

#define EFFECTS_DEBUGGER	"tagoras"

inherit ADVANCED_EFFECT;

#define SEVERITY_LIGHT			1
#define SEVERITY_MODERATE		2
#define SEVERITY_SERIOUS		3
#define SEVERITY_CRITICAL		4

#define SEVERITY_DAMAGE			5			// Máximo a añadir por nivel del caster según la severidad

#define CURE					1
#define INFLICT					-1

//------------------------------------------------------------------------------

private int nCureInflict;
private int nSeverity;

public int QueryCureInflict() { return nCureInflict || CURE; }
public int SetCureInflict(int i) { return nCureInflict = (i>0?CURE:INFLICT); }

public int QuerySeverity() { return nSeverity || SEVERITY_LIGHT; }
public int SetSeverity(int i)
{
	switch (i) {
		case SEVERITY_LIGHT: case SEVERITY_MODERATE: case SEVERITY_SERIOUS: case SEVERITY_CRITICAL: nSeverity = i; break;
	}
	return QuerySeverity();
}

public string QueryAffectedMessage()
{
	string s_name;
	int sev;

	s_name = (CURE == QueryCureInflict()?"Curar":"Infligir") + " heridas " + ({"leves", "moderadas", "graves", "críticas"})[QuerySeverity()];
	
	 
	return sprintf("%-30'.'s: %s\n", s_name, "Recibes "+QuerySeverity()+"d8 + 1 por nivel del recitador (máx:+"+SEVERITY_DAMAGE*QuerySeverity()+") "+(CURE==QueryCureInflict()?"vida":"daño")+".");
}

//------------------------------------------------------------------------------

public int InitEffect()
{
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	// TODO: Si fuera contra un undead se tendría que mirar en el cso de curar
	if (INFLICT==QueryCureInflict())
	{
		if (present(QueryCasterName(), environment(QueryAffected())) && (QueryCasterName()!=QueryAffected()->QueryRealName())) 
		{
			QueryAffected()->Kill(find_object(QueryCasterName()));
			return ::InitEffect();
		}
		else
			return notify_fail("¿No querrás infligirte heridas, verdad?\n", NOTIFY_NOT_VALID);
	}
}

public int ExecEffect()
{
	int damage = 0, i, caster_level; 

	caster_level = QueryCasterLevel(1);
	damage = d8(QuerySeverity()) + (caster_level <= (5*QuerySeverity())?caster_level:(5*QuerySeverity()));
	
	// TODO: En los undead sería al curar
	if (INFLICT==QueryCureInflict())
	{
		// Saving Throw
		if (SavingThrow())
			damage /= 2;
		damage = QueryAffected()->Defend(damage, TM_INTR, DEFEND_SPELL | DEFEND_NOMSG | DEFEND_NOLIV);
		if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
 			dtell(EFFECTS_DEBUGGER, sprintf("Daño realizado por inflict wounds: %d\n", damage));
		// TODO: Se podrían mejorar los mensajes con el combatmaster
	}
	else
	{
		QueryAffected()->SetHP(QueryAffected()->QueryHP()+damage);
		if (QueryAffected()->QueryHP() > QueryAffected()->QueryMaxHP())
			QueryAffected()->SetHP(QueryAffected()->QueryMaxHP());
	}

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
	AddId("_wounds");
	SetSaveType(SAVE_TYPE_WILL);
}

//------------------------------------------------------------------------------
