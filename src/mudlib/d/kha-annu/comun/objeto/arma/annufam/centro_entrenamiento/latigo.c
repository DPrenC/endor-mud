/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief un l�tigo
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Este es el l�tigo que los reclutas enanos de Annufam utilizan en sus entrenamientos. Est� fabricado con cuero y en su empu�adura puedes observar grabada la cabeza de un le�n.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_LATIGO, 2, P_SIZE_GENERIC, M_CUERO);
	SetLong("Este es el l�tigo que los reclutas enanos de Annufam utilizan en sus entrenamientos. Est� fabricado con cuero y en su empu�adura puedes observar grabada la cabeza de un le�n.\n");
	AddId(({"latigo"}));
}
