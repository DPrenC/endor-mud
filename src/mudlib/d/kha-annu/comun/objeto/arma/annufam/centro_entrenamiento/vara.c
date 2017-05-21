/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief una vara
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Esta es la vara oficial que los reclutas de Annufam utilizan en sus entrenamientos. Está construida en acero y en su empuñadura puedes ver grabada la cabeza de un león.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_VARA, 5, P_SIZE_GENERIC, M_ACERO);
	SetLong("Esta es la vara oficial que los reclutas de Annufam utilizan en sus entrenamientos. Está construida en acero y en su empuñadura puedes ver grabada la cabeza de un león.\n");
}
