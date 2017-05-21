/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_bullsstrength.c
Autor: [T] Tagoras
Fecha: 04/03/2009
Descripcion: Efecto fuerza de toro basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Bull¿s Strength
Transmutation
Level: 	Clr 2, Drd 2, Pal 2, Sor/Wiz 2, Strength 2
Components: 	V, S, M/DF
Casting Time: 	1 standard action
Range: 	Touch
Target: 	Creature touched
Duration: 	1 min./level
Saving Throw: 	Will negates (harmless)
Spell Resistance: 	Yes (harmless)

The subject becomes stronger. The spell grants a +4 enhancement bonus to Strength, adding the usual benefits to melee attack rolls, melee damage rolls, and other uses of the Strength modifier.
Arcane Material Component

A few hairs, or a pinch of dung, from a bull. 
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <ts.h>

#define EFFECTS_DEBUGGER	"tagoras"

inherit ADVANCED_EFFECT;

//------------------------------------------------------------------------------

public string QueryAffectedMessage()
{
	int segundos, minutos, horas;
	string tiempo;

	segundos = QueryTimeLeft() * 2;  // Un turno en Simauria dura 2 segundos
	minutos = segundos/60;
	segundos %= 60;
	horas = minutos/60;
	minutos %= 60;

	tiempo = "";
	if (horas)
		tiempo += horas+" hora"+(horas==1?"":"s");
	if (minutos)
	{
		if (strlen(tiempo)) tiempo += " ";
		tiempo += minutos+" minuto"+(minutos==1?"":"s");
	}
	if (segundos)
	{
		if (strlen(tiempo)) tiempo += " ";
		tiempo += segundos+" segundo"+(segundos==1?"":"s");
	}

	return sprintf("%-30'.'s: %s\n", "Fuerza de toro", "+4 FUE durante "+tiempo+".");
}

//------------------------------------------------------------------------------

public int InitEffect() {
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	QueryAffected()->AddStrBonus(4);
	return ::InitEffect();
}

public int EndEffect() {
	QueryAffected()->AddStrBonus(-4);
	return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_bullsstrength");
}

//------------------------------------------------------------------------------
