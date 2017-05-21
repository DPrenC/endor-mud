/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_bearsendurance.c
Autor: [T] Tagoras
Fecha: 04/03/2009
Descripcion: Efecto resistencia de oso basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Bear.s Endurance
Transmutation
Level: 	Clr 2, Drd 2, Rgr 2, Sor/Wiz 2
Components: 	V, S, DF
Casting Time: 	1 standard action
Range: 	Touch
Target: 	Creature touched
Duration: 	1 min./level
Saving Throw: 	Will negates (harmless)
Spell Resistance: 	Yes

The affected creature gains greater vitality and stamina. The spell grants the subject a +4 enhancement bonus to Constitution, which adds the usual benefits to hit points, Fortitude saves, Constitution checks, and so forth.

Hit points gained by a temporary increase in Constitution score are not temporary hit points. They go away when the subject.s Constitution drops back to normal. They are not lost first as temporary hit points are. 
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

	return sprintf("%-30'.'s: %s\n", "Resistencia de oso", "+4 CON durante "+tiempo+".");
}

//------------------------------------------------------------------------------

public int InitEffect() {
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	QueryAffected()->AddConBonus(4);
	return ::InitEffect();
}

public int EndEffect() {
	QueryAffected()->AddConBonus(-4);
	return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_bearsendurance");
}

//------------------------------------------------------------------------------
