/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_catsgrace.c
Autor: [T] Tagoras
Fecha: 04/03/2009
Descripcion: Efecto gracia felina basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Cat¿s Grace
Transmutation
Level: 	Brd 2, Drd 2, Rgr 2, Sor/Wiz 2
Components: 	V, S, M
Casting Time: 	1 standard action
Range: 	Touch
Target: 	Creature touched
Duration: 	1 min./level
Saving Throw: 	Will negates (harmless)
Spell Resistance: 	Yes

The transmuted creature becomes more graceful, agile, and coordinated. The spell grants a +4 enhancement bonus to Dexterity, adding the usual benefits to AC, Reflex saves, and other uses of the Dexterity modifier.
Material Component

A pinch of cat fur. 
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

	return sprintf("%-30'.'s: %s\n", "Gracia felina", "+4 DEX durante "+tiempo+".");
}

//------------------------------------------------------------------------------

public int InitEffect() {
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	QueryAffected()->AddDexBonus(4);
	return ::InitEffect();
}

public int EndEffect() {
	QueryAffected()->AddDexBonus(-4);
	return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_catsgrace");
}

//------------------------------------------------------------------------------
