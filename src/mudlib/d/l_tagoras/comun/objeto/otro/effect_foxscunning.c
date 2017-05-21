/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_foxscunning.c
Autor: [T] Tagoras
Fecha: 23/04/2009
Descripcion: Efecto astucia de zorro basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Fox.s Cunning
Transmutation
Level: 	Brd 2, Sor/Wiz 2
Components: 	V, S, M/DF
Casting Time: 	1 standard action
Range: 	Touch
Target: 	Creature touched
Duration: 	1 min./level
Saving Throw: 	Will negates (harmless)
Spell Resistance: 	Yes

The transmuted creature becomes smarter. The spell grants a +4 enhancement bonus to Intelligence, adding the usual benefits to Intelligence-based skill checks and other uses of the Intelligence modifier. Wizards (and other spellcasters who rely on Intelligence) affected by this spell do not gain any additional bonus spells for the increased Intelligence, but the save DCs for spells they cast while under this spell.s effect do increase. This spell doesn.t grant extra skill points.
Arcane Material Component

A few hairs, or a pinch of dung, from a fox. 
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

	segundos = QueryTimeLeft() * 2;	 // Un turno en Simauria dura 2 segundos
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

	return sprintf("%-30'.'s: %s\n", "Astucia de zorro", "+4 INT durante "+tiempo+".");
}

//------------------------------------------------------------------------------

public int InitEffect() {
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	QueryAffected()->AddIntBonus(4);
	return ::InitEffect();
}

public int EndEffect() {
	QueryAffected()->AddIntBonus(-4);
	return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_foxscunning");
}

//------------------------------------------------------------------------------
