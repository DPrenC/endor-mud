/*
Fichero: /d/l_tagoras/comun/objeto/otro/effect_invisibility.c
Autor: [T] Tagoras
Fecha: 24/04/2009
Descripcion: Efecto invisibilidad basado en el sistema de efectos de Nyh

--------------------------------------------------------------------------------
Invisibility
Illusion (Glamer)
Level: 	Brd 2, Sor/Wiz 2, Trickery 2
Components: 	V, S, M/DF
Casting Time: 	1 standard action
Range: 	Personal or touch
Target: 	You or a creature or object weighing no more than 100 lb./level
Duration: 	1 min./level (D)
Saving Throw: 	Will negates (harmless) or Will negates (harmless, object)
Spell Resistance: 	Yes (harmless) or Yes (harmless, object)

The creature or object touched becomes invisible, vanishing from sight, even from darkvision. If the recipient is a creature carrying gear, that vanishes, too. If you cast the spell on someone else, neither you nor your allies can see the subject, unless you can normally see invisible things or you employ magic to do so.

Items dropped or put down by an invisible creature become visible; items picked up disappear if tucked into the clothing or pouches worn by the creature. Light, however, never becomes invisible, although a source of light can become so (thus, the effect is that of a light with no visible source). Any part of an item that the subject carries but that extends more than 10 feet from it becomes visible.

Of course, the subject is not magically silenced, and certain other conditions can render the recipient detectable (such as stepping in a puddle). The spell ends if the subject attacks any creature. For purposes of this spell, an attack includes any spell targeting a foe or whose area or effect includes a foe. (Exactly who is a foe depends on the invisible character.s perceptions.) Actions directed at unattended objects do not break the spell. Causing harm indirectly is not an attack. Thus, an invisible being can open doors, talk, eat, climb stairs, summon monsters and have them attack, cut the ropes holding a rope bridge while enemies are on the bridge, remotely trigger traps, open a portcullis to release attack dogs, and so forth. If the subject attacks directly, however, it immediately becomes visible along with all its gear. Spells such as bless that specifically affect allies but not foes are not attacks for this purpose, even when they include foes in their area.

Invisibility can be made permanent (on objects only) with a permanency spell.
Arcane Material Component

An eyelash encased in a bit of gum arabic. 
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

	return sprintf("%-30'.'s: %s\n", "Invisibilidad", "Eres invisible durante "+tiempo+".");
}

//------------------------------------------------------------------------------

public int InitEffect() {
	int c_lev = QueryCasterLevel(1);

	if (!CheckSomatic())
		return notify_fail("Necesitas tener al menos una mano libre.\n", NOTIFY_NOT_VALID);
	// El objetivo puedes pesar máximo 100lb por nivel (100lb = 45630gr)
	if (QueryAffected()->QueryWeight() > QueryCasterLevel(1)*45630)
		return notify_fail(CAP(QueryAffected()->QueryRealName())+" pesa demasiado.\n", NOTIFY_NOT_VALID);
	QueryAffected()->SetInvis(1);
	return ::InitEffect();
}

public int ExecEffect() {
	if (QueryAffected()->Fighting())
		remove();
	return ::ExecEffect();
}

public int EndEffect() {
	QueryAffected()->SetInvis(0);
	return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	AddId("_invisibility");
}

//------------------------------------------------------------------------------
