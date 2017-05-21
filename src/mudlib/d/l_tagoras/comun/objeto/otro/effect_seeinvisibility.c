/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_seeinvisibility.c
Autor: [T] Tagoras
Fecha: 24/04/2009
Descripcion: Efecto ver invisibilidad basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
See Invisibility
Divination
Level: 	Brd 3, Sor/Wiz 2
Components: 	V, S, M
Casting Time: 	1 standard action
Range: 	Personal
Target: 	You
Duration: 	10 min./level (D)

You can see any objects or beings that are invisible within your range of vision, as well as any that are ethereal, as if they were normally visible. Such creatures are visible to you as translucent shapes, allowing you easily to discern the difference between visible, invisible, and ethereal creatures.

The spell does not reveal the method used to obtain invisibility. It does not reveal illusions or enable you to see through opaque objects. It does not reveal creatures who are simply hiding, concealed, or otherwise hard to see.

See invisibility can be made permanent with a permanency spell.
Material Component

A pinch of talc and a small sprinkling of powdered silver. 
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

	return sprintf("%-30'.'s: %s\n", "Ver lo invisible", "Ves lo invisible durante "+tiempo+".");
}

//------------------------------------------------------------------------------

public int InitEffect() {
	int c_lev = QueryCasterLevel(1);

	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	// Sólo sobre uno mismo
	if (QueryAffected()->QueryRealName() != QueryCaster()->QueryRealName())
		return notify_fail("Sólo puedes realizar este hechizo sobre tu persona.\n", NOTIFY_NOT_VALID);
	QueryAffected()->Set(P_SEE_INVIS, Query(P_SEE_INVIS)+1);
	return ::InitEffect();
}

public int EndEffect() {
	QueryAffected()->Set(P_SEE_INVIS, Query(P_SEE_INVIS)-1);
	return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_seeinvisibility");
}

//------------------------------------------------------------------------------
