/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_barkskin.c
Autor: [T] Tagoras
Fecha: 04/03/2009
Descripcion: Efecto piel robliza basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Barkskin
Transmutation
Level: 	Drd 2, Rgr 2, Plant 2
Components: 	V, S, DF
Casting Time: 	1 standard action
Range: 	Touch
Target: 	Living creature touched
Duration: 	10 min./level
Saving Throw: 	None
Spell Resistance: 	Yes (harmless)

Barkskin toughens a creature.s skin. The effect grants a +2 enhancement bonus to the creature.s existing natural armor bonus. This enhancement bonus increases by 1 for every three caster levels above 3rd, to a maximum of +5 at caster level 12th.

The enhancement bonus provided by barkskin stacks with the target.s natural armor bonus, but not with other enhancement bonuses to natural armor. A creature without natural armor has an effective natural armor bonus of +0. 
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

	return sprintf("%-30'.'s: %s\n", "Piel robliza", "+"+QueryBonus()+" AC durante "+tiempo+".");
}

//------------------------------------------------------------------------------

public int InitEffect() {
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	if (!QueryBonus())
	{
		SetBonus (2+(((QueryCasterLevel(1) < 12 ? QueryCasterLevel(1) : 12)-3)/3));
		//QueryAffected()->AddBonus(P_AC, QueryBonus());
	}
	QueryAffected()->SetAC(QueryAffected()->QueryAC()+QueryBonus());
	return ::InitEffect();
}

public int EndEffect() {
	//QueryAffected()->AddBonus(P_AC, -QueryBonus());
	QueryAffected()->SetAC(QueryAffected()->QueryAC()-QueryBonus());
	return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_barkskin");
}

//------------------------------------------------------------------------------
