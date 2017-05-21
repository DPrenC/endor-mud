/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief un látigo
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Este es el látigo que los reclutas enanos de Annufam utilizan en sus entrenamientos. Está fabricado con cuero y en su empuñadura puedes observar grabada la cabeza de un león.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_LATIGO, 2, P_SIZE_GENERIC, M_CUERO);
	SetLong("Este es el látigo que los reclutas enanos de Annufam utilizan en sus entrenamientos. Está fabricado con cuero y en su empuñadura puedes observar grabada la cabeza de un león.\n");
	AddId(({"latigo"}));
}
