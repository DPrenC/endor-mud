/* vi: set tabstop=4 */
/** @file armadura_test.c
	@brief un escudo
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Es un escudo grande y muy resistente que los reclutas de Annufam utilizan en sus entrenamientos. Está construido en acero y en el puedes ver que tiene inscrita la cabeza de un león.
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(AT_ESCUDO, 7, P_SIZE_LARGE, M_ACERO);
	SetLong("Es un escudo grande y muy resistente que los reclutas de Annufam utilizan en sus entrenamientos. Está construido en acero y en él puedes ver que tiene inscrita la cabeza de un león.\n");
}
