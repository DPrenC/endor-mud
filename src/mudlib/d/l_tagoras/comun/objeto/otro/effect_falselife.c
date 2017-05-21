/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_falselife.c
Autor: [T] Tagoras
Fecha: 21/04/2009
Descripcion: Efecto falsa vida basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
False Life
Necromancy
Level: 	Sor/Wiz 2
Components: 	V, S, M
Casting Time: 	1 standard action
Range: 	Personal
Target: 	You
Duration: 	1 hour/level or until discharged; see text

You harness the power of unlife to grant yourself a limited ability to avoid death. While this spell is in effect, you gain temporary hit points equal to 1d10 +1 per caster level (maximum +10).
Material Component

A small amount of alcohol or distilled spirits, which you use to trace certain sigils on your body during casting. These sigils cannot be seen once the alcohol or spirits evaporate.
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <ts.h>

#define EFFECTS_DEBUGGER	"tagoras"

inherit ADVANCED_EFFECT;

//------------------------------------------------------------------------------

protected int nBonus;
protected int nBaseHP;

public int QueryBaseHP() { return nBaseHP; }
public int SetBaseHP(int i) { return nBaseHP=i; }

public int QueryBonus() { return nBonus||0; }
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

	return sprintf("%-30'.'s: %s\n", "Falsa vida", "+"+QueryBonus()+" PG durante "+tiempo+".");
}

//------------------------------------------------------------------------------

public int InitEffect() {
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	if (QueryAffected()->QueryRealName() != QueryCaster()->QueryRealName())
		return notify_fail("Sólo puedes realizar este hechizo sobre tu persona.\n", NOTIFY_NOT_VALID);

	if (!QueryBonus())
	{
		SetBonus (d10()+(QueryCasterLevel(1) <= 10 ? QueryCasterLevel(1) : 10));
		SetBaseHP(QueryAffected()->QueryHP());
		QueryAffected()->AddHP(QueryBonus());
	}
	return ::InitEffect();
}

public int ExecEffect() {
	if (QueryAffected()->QueryHP() <= QueryBaseHP())
		remove();
	return ::ExecEffect();
}

public int EndEffect() {
	if (QueryAffected()->QueryHP() > QueryBaseHP())
	{
		QueryAffected()->AddHP(-QueryBonus());
		if (QueryAffected()->QueryHP() < QueryBaseHP())
			QueryAffected()->SetHP(QueryBaseHP());
	}
	return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_falselife");
}

//------------------------------------------------------------------------------
