/* vi: set tabstop=4 */
/** @file corona_rak.c
	@brief la corona del conocimiento
	@author SimBuilder
	@version 1.00
	@date 2009-01-08

	Es una corona de un material desconocido que fue hallada tras el desastre de Atalantë, una legendaria isla que se dice desapareció de la noche a la mañana por haber intentado rivalizar con los dioses. Hay algo grabado en ella.
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

public varargs mixed ChkEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return EQ_OK;
	if (wielder->QueryGuildLevel() < 100)
	{
		tell_object(wielder, "No eres lo suficientemente poderoso para llevar esta corona.\n");
		return EQ_FORBID;
	}
	return ::ChkEquip(wielder, equipment, flags);
}

public varargs void NotifyEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	tell_object(wielder, "Sientes que tu cerebro bulle de actividad frenética.\n");
	wielder->AddIntBonus(1);
	SetBright(35);
	::NotifyEquip(wielder, equipment, flags);
}

public varargs void NotifyUnequip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	tell_object(wielder, "Notas como si te costase más pensar.\n");
	wielder->AddIntBonus(-1);
	SetBright(0);
	::NotifyUnequip(wielder, equipment, flags);
}

create()
{
	::create();
	SetStandard(AT_CASCO, 25, P_SIZE_GENERIC, M_ESPECIAL);
	SetShort("la corona del conocimiento");
	SetLong("Es una corona de un material desconocido que fue hallada tras el desastre de Atalantë, una legendaria isla que se dice desapareció de la noche a la mañana por haber intentado rivalizar con los dioses. Hay algo grabado en ella.\n");
	AddId(({"corona", "corona del conocimiento"}));
	Set(P_GENDER, GENDER_FEMALE);
	AddSubDetail(({"grabado"}),"Hay inscritos unos símbolos en una lengua ya tiempo olvidada que desconoces. Sin embargo una letanía susurra desde el fondo de tu mente: \'El conocimiento es poder\'.\n");
	SetMagic(1);
}
