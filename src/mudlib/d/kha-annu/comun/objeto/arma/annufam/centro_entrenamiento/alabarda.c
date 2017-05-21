/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief una alabarda
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Es una de las alabardas que utilizan los reclutas enanos de Annufam. Está fabricada en madera y hierro y en su empuñadura puedes ver tallada la cabeza de un león.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_ALABARDA, 10, P_SIZE_GENERIC, M_HIERRO);
	SetLong("Es una de las alabardas que utilizan los reclutas enanos de Annufam. Está fabricada en madera y hierro y en su empuñadura puedes ver tallada la cabeza de un león.\n");
}
