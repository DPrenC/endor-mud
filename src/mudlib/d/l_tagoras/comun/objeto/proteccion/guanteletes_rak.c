/* vi: set tabstop=4 */
/** @file guanteletes_rak.c
	@brief los guanteletes del miedo
	@author SimBuilder
	@version 1.00
	@date 2009-01-08

	Estos guanteletes fueron forjados con la esencia de las almas torturadas por antiguos y olvidados demonios. No querrías sentir su helado toque en tu carne.
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

public varargs mixed ChkEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return EQ_OK;
	if (wielder->QueryGuildLevel() < 100)
	{
		tell_object(wielder, "Tus manos se congelan al intentar ponerte estos guanteletes.\n");
		return EQ_FORBID;
	}
	if ((wielder->QueryAlign()>-900))
	{
		tell_object(wielder, "Tu corazón es demasiado cálido para soportar el contraste de temperaturas.\n");
		return EQ_FORBID;
	}
	return ::ChkEquip(wielder, equipment, flags);
}

public varargs void NotifyEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	tell_object(wielder, "De repente te sientes más poderoso.\n");
	wielder->AddStrBonus(1);
	::NotifyEquip(wielder, equipment, flags);
}

public varargs void NotifyUnequip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	tell_object(wielder, "Sientes que algo de poder te abandona.\n");
	wielder->AddStrBonus(-1);
	::NotifyUnequip(wielder, equipment, flags);
}

create()
{
	::create();
	SetStandard(AT_GUANTES, 25, P_SIZE_GENERIC, M_ESPECIAL);
	SetShort("los guanteletes del miedo");
	SetLong("Estos guanteletes fueron forjados con la esencia de las almas torturadas por antiguos y olvidados demonios. No querrías sentir su helado toque en tu carne.\n");
	AddId(({"guanteletes", "guanteletes del miedo"}));
	SetMagic(1);
}
