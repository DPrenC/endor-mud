#include <properties.h>

#define DND_MAX_LEVEL   20                  // En DND el nivel máximo es 20
#define SIM_MAX_LEVEL   HLP_RLVL            // En Simauria no hay máximo pero podemos tomar el de JAN o HLP

/*
Melee basic attack Strength vs. AC
Ranged basic attack Dexterity vs. AC
Stunning steel Strength vs. Fortitude
Fireball Intelligence vs. Reflex
Cause fear Wisdom vs. Will
*/
public int CalcBaseAttackBonus(object atk, int modifier)
{
	return ((atk->QueryLevel()*DND_MAX_LEVEL)/SIM_MAX_LEVEL)/2 + modifier;
}

// -------------------------------------
// Modificadores de ataque
// -------------------------------------

/*
ATTACK MODIFIERS
Circumstance										Modifier
Combat advantage against target							+2
Attacker is prone										-2
Attacker is restrained 									-2
Target has cover 										-2
Target has superior cover 								-5
Target has concealment (melee and ranged only)			-2
Target has total concealment (melee and ranged only)	-5
Long range (weapon attacks only)						-2
Charge attack (melee only)								+1
*/
public int CalcAttackModifiers(object atk, object def)
{
	int bonus = 0;

	// Ventaja de combate
	if (HasCombatAdvantage(atk, def))
		bonus += 2;	
	// Boca abajo?
	if (atk->QueryStatusResting() || atk->QueryStatusSleeping())
		bonus -= 2;
	// Restrained;
	if (atk->QueryParalyzed())
		bonus -= 2;

	
}

/*
The attacker sees the defender &

When a defender is . . .
Balancing (page 180)
Blinded (page 277)
Climbing (page 182)
Dazed (page 277)
Flanked by the attacker (page 285)
Helpless (page 277)
Prone (melee attacks only) (page 277)
Restrained (page 277)
Running (page 291)
Squeezing (page 292)
Stunned (page 277)
Surprised (page 277)
Unable to see the attacker (page 281)
Unaware of you (page 188)
Unconscious (page 277)
*/
public int HasCombatAdvantage(object atk, object def)
{
	// TODO: Se tendría que cambiar por si el atk puede ver al def
	if (atk-Query(P_BLIND))
		return 0;
	// El defender
	if (Def->QueryInvis())
		return 0;
	if (def->Query(P_BLIND) || def->QueryDisabled() || def->QueryStatusHelpless() || def->QueryStatusTripped() || def->QueryStatusSleeping() || def->QueryStatusResting() || def->QueryParalyzed())
		return 1;
}
