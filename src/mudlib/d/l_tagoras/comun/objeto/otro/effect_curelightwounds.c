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
*/

#include "path.h"

inherit EFFECT_WOUNDS;

#define SEVERITY_LIGHT			1
#define SEVERITY_MODERATE		2
#define SEVERITY_SERIOUS		3
#define SEVERITY_CRITICAL		4

#define CURE					1
#define INFLICT					-1

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	SetCureInflict(CURE);
	SetSeverity(SEVERITY_LIGHT);
}

//------------------------------------------------------------------------------
