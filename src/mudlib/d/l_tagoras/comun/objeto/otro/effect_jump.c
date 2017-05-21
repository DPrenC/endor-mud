/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_jump.c
Autor: [T] Tagoras
Fecha: 24/04/2009
Descripcion: Efecto salto basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Jump
Transmutation
Level: 	Drd 1, Rgr 1, Sor/Wiz 1
Components: 	V, S, M
Casting Time: 	1 standard action
Range: 	Touch
Target: 	Creature touched
Duration: 	1 min./level (D)
Saving Throw: 	Will negates (harmless)
Spell Resistance: 	Yes

The subject gets a +10 enhancement bonus on Jump checks. The enhancement bonus increases to +20 at caster level 5th, and to +30 (the maximum) at caster level 9th.
Material Component

A grasshopper.s hind leg, which you break when the spell is cast. 
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <ts.h>

#define EFFECTS_DEBUGGER	"tagoras"

inherit ADVANCED_EFFECT;

//------------------------------------------------------------------------------

protected int nBonus;

public int QueryBonus() { return nBonus; }
public int SetBonus(int i) { return nBonus=i; }

public string QueryAffectedMessage()
{
	int segundos, minutos, horas;
	string tiempo;
	
	segundos = QueryTimeLeft() * 2;		// Un turno en Simauria dura 2 segundos
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

	return sprintf("%-30'.'s: %s\n", "Salto", "+"+QueryBonus()+" en saltar durante "+tiempo+".");
}

//------------------------------------------------------------------------------

public int InitEffect() {
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	if (!QueryBonus())
	{
		SetBonus(10);
		if (QueryCasterLevel(1) >= 5);
			SetBonus(20);
		if (QueryCasterLevel(1) >= 9);
			SetBonus(30);
		QueryAffected()->SetSkillLevel("saltar", QueryAffected()->QuerySkillLevel("saltar")+QueryBonus());
	}
	return ::InitEffect();
}

public int EndEffect() {
	QueryAffected()->SetSkillLevel("saltar", QueryAffected()->QuerySkillLevel("saltar")-QueryBonus());
	return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_jump");
}

//------------------------------------------------------------------------------
