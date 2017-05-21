/* vi: set tabstop=4 */
/** @file amuleto_altriv.c
	@brief el amuleto de Altriv
	@author Tagoras
	@version 1.00
	@date 2009-03-07

	Es el amuleto de Altriv, hecho del mismo trozo de mithril con el que se forjó la empuñadura de su hacha. Se dice, que en estos casos, los objetos así realizados trazan un vínculo mágico entre ellos. Tiene un grabado muy especial.
*/

inherit ARMOUR;

#include <combat.h>
#include <guild.h>
#include <properties.h>			// Ya incluye materials.h

public varargs void NotifyEquip(object wielder, object equipment, int flags)
{
	int con_bonus = 1;

	if (equipment != TO) return;
	if (wielder->QueryRace() == "enano")
		con_bonus++;
	if (wielder->QueryGuild() == GC_GUERREROS)
		con_bonus++;
	tell_object(wielder, "Te sientes "+(({"un poco", "bastante", "mucho"})[con_bonus-1])+" más vigoroso\n");
	wielder->AddConBonus(con_bonus);
	::NotifyEquip(wielder, equipment, flags);
}

public varargs void NotifyUnequip(object wielder, object equipment, int flags)
{
	int con_bonus = 1;

	if (equipment != TO) return;
	if (wielder->QueryRace() == "enano")
		con_bonus++;
	if (wielder->QueryGuild() == GC_GUERREROS)
		con_bonus++;
	tell_object(wielder, "Te sientes "+(({"un poco", "bastante", "mucho"})[con_bonus-1])+" menos vigoroso\n");
	wielder->AddConBonus(-con_bonus);
	::NotifyUnequip(wielder, equipment, flags);
}

create()
{
	::create();
	SetStandard(AT_AMULETO, 1, P_SIZE_GENERIC, M_MITHRIL);
	SetShort("el amuleto de Altriv");
	SetLong("Es el amuleto de Altriv, hecho del mismo trozo de mithril con el que se forjó la empuñadura de su hacha. Se dice, que en estos casos, los objetos así realizados trazan un vínculo mágico entre ellos. Tiene un grabado muy especial.\n");
	AddId(({"amuleto_altriv"}));
	AddAdjective(({"el", "de", "altriv"}));
	AddSubDetail(({"grabado"}),"Es una imagen del hacha de Altriv. Es curioso, parece que se reduce y se agranda contínuamente.\n");
	SetMagic(1);
}
