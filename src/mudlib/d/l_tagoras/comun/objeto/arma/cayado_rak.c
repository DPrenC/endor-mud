/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief un cayado negro
	@author SimBuilder
	@version 1.00
	@date 2008-09-12

	Este es el cayado de Rak-nal-turi. Está realizado en algún material que te es desconocido. No refleja ninguna luz por lo que a tus ojos es simplemente negro, pero crees que debe ser algún tipo de efecto mágico.
	Hay una runas grabadas.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h
#include <guild.h>				// GC_CONJURADORES

public varargs mixed ChkEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return EQ_OK;
	if ((wielder->QueryAlign()>-900))
	{
		tell_object(wielder, "Sólo el mal puede empuñar este cayado.\n");
		return EQ_FORBID;
	}
	return ::ChkEquip(wielder, equipment, flags);
}

public varargs void NotifyEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	if (wielder->QueryGuild() == GC_CONJURADORES)
	{
	SetWC(QueryWC()+5);
	}
	::NotifyEquip(wielder, equipment, flags);
}

public varargs void NotifyUnequip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	if (wielder->QueryGuild() == GC_CONJURADORES)
	{
	SetWC(QueryWC()-5);
	}
	::NotifyUnequip(wielder, equipment, flags);
}

create()
{
	::create();
	SetStandard(WT_VARA, 16, P_SIZE_GENERIC, M_ESPECIAL);
	SetShort("un cayado negro");
	SetLong("Este es el cayado de Rak-nal-turi. Está realizado en algún material que te es desconocido. No refleja ninguna luz por lo que a tus ojos es simplemente negro, pero crees que debe ser algún tipo de efecto mágico.\n"
	"Hay una runas grabadas.\n");
	AddId(({"cayado"}));
	AddAdjective(({"negro"}));
	Set(P_GENDER, GENDER_MALE);
	AddSubDetail(({"runas", "grabado", "runas grabadas"}),"Las runas dicen: \'Para mi siervo más fiel\'\n");
	SetMagic(1);
}
