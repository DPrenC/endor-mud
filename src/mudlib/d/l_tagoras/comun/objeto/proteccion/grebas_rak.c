/* vi: set tabstop=4 */
/** @file grebas_rak.c
	@brief las grebas oshkuras
	@author SimBuilder
	@version 1.00
	@date 2009-01-08

	Estas grebas les fueron entregadas a Rak-nal-turi por la diosa Sharanna. Su color negro no refleja luz alguna. Tiene grabada una inscripción.
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

public varargs mixed ChkEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return EQ_OK;
	if (wielder->QueryGuildLevel() < 100)
	{
		tell_object(wielder, "Sólo los grandes entre los grandes puedes llevar estas grebas.\n");
		return EQ_FORBID;
	}
	if ((wielder->QueryAlign()>-900))
	{
		tell_object(wielder, "No eres aún un fiel servidor de la muerte para poder llevar las grebas.\n");
		return EQ_FORBID;
	}
	return ::ChkEquip(wielder, equipment, flags);
}

public varargs void NotifyEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	tell_object(wielder, "Extrañamente te sientes más diestro.\n");
	wielder->AddDexBonus(1);
	::NotifyEquip(wielder, equipment, flags);
}

public varargs void NotifyUnequip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	tell_object(wielder, "Parece que eres un poco más torpe.\n");
	wielder->AddDexBonus(-1);
	::NotifyUnequip(wielder, equipment, flags);
}

create()
{
	::create();
	SetStandard(AT_GREBAS, 25, P_SIZE_GENERIC, M_ESPECIAL);
	SetShort("unas grebas oshkuras");
	SetLong("Estas grebas les fueron entregadas a Rak-nal-turi por la diosa Sharanna. Su color negro no refleja luz alguna. Tiene grabada una inscripción.\n");
	AddId(({"grebas"}));
	AddAdjective(({"oshkuras"}));
	Set(P_GENDER, GENDER_FEMALE);
	AddSubDetail(({"inscripcion", "inscripción"}),"Examinas la inscripción y lees: \'Sólo aquel que sirve a la muerte puede llevar estas grebas\'.\n");
	SetMagic(1);
}
