/* vi: set tabstop=4 */
/** @file coraza_rak.c
	@brief La coraza de Sharanna
	@author SimBuilder
	@version 1.00
	@date 2009-01-08

	Esta coraza es muy especial. Se dice que la propia diosa de la muerte le dio parte de su poder al usar un mechón de cabello al forjarla. Tiene un grabado en el torso.
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

public varargs mixed ChkEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return EQ_OK;
	if (wielder->QueryGuildLevel() < 100)
	{
		tell_object(wielder, "Tendrás que crecer un poco antes de poner llevar esta magnífica coraza.\n");
		return EQ_FORBID;
	}
	if ((wielder->QueryAlign()>-900))
	{
		tell_object(wielder, "Eres demasiado bondadoso para poder usar esta coraza.\n");
		return EQ_FORBID;
	}
	return ::ChkEquip(wielder, equipment, flags);
}

public varargs void NotifyEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	tell_object(wielder, "Sientes que tu constitución aumenta.\n");
	wielder->AddConBonus(1);
	::NotifyEquip(wielder, equipment, flags);
}

public varargs void NotifyUnequip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	tell_object(wielder, "Sientes que tu constitución disminuye.\n");
	wielder->AddConBonus(-1);
	::NotifyUnequip(wielder, equipment, flags);
}

create()
{
	::create();
	SetStandard(AT_CORAZA, 25, P_SIZE_GENERIC, M_ESPECIAL);
	SetShort("la coraza de Sharanna");
	SetLong("Esta coraza es muy especial. Se dice que la propia diosa de la muerte le dio parte de su poder al usar un mechón de cabello al forjarla. Tiene un grabado en el torso.\n");
	AddId(({"coraza", "coraza de sharanna"}));
	AddSubDetail(({"grabado"}),"Es el rostro de una bella mujer, no puedes dejar de contemplarlo y, sin embargo, un miedo irracional se expande por todo tu ser.\n");
	SetMagic(1);
}
