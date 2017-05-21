/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_magearmor.c
Autor: [T] Tagoras
Fecha: 24/04/2009
Descripcion: Efecto armadura de mago basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Mage Armor
Conjuration (Creation) [Force]
Level: 	Sor/Wiz 1
Components: 	V, S, F
Casting Time: 	1 standard action
Range: 	Touch
Target: 	Creature touched
Duration: 	1 hour/level (D)
Saving Throw: 	Will negates (harmless)
Spell Resistance: 	No

An invisible but tangible field of force surrounds the subject of a mage armor spell, providing a +4 armor bonus to AC.

Unlike mundane armor, mage armor entails no armor check penalty, arcane spell failure chance, or speed reduction. Since mage armor is made of force, incorporeal creatures can.t bypass it the way they do normal armor.
Focus

A piece of cured leather. 
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

	return sprintf("%-30'.'s: %s\n", "Armadura de mago", "+4 AC durante "+tiempo+".");
}

//------------------------------------------------------------------------------

public int InitEffect() {
	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	QueryAffected()->SetAC(QueryAffected()->QueryAC()+4);
	return ::InitEffect();
}

public int EndEffect() {
	//QueryAffected()->AddBonus(P_AC, -QueryBonus());
	QueryAffected()->SetAC(QueryAffected()->QueryAC()-4);
	return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_magearmor");
}

//------------------------------------------------------------------------------
