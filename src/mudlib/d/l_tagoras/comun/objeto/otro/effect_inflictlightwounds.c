/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_inflictlightwounds.c
Autor: [T] Tagoras
Fecha: 04/03/2009
Descripcion: Efecto infligir heridas leves basado en el sistema de efectos de Nyh

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
*/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <ts.h>
#include <wizlevels.h>

#define EFFECTS_DEBUGGER	"tagoras"

inherit EFFECT_WOUNDS;

#define SEVERITY_LIGHT			1
#define SEVERITY_MODERATE		2
#define SEVERITY_SERIOUS		3
#define SEVERITY_CRITICAL		4

#define SEVERITY_DAMAGE			5			// Máximo a añadir por nivel del caster según la severidad

#define CURE					1
#define INFLICT					-1

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	SetCureInflict(INFLICT);
	SetSeverity(SEVERITY_LIGHT);
}

//------------------------------------------------------------------------------
