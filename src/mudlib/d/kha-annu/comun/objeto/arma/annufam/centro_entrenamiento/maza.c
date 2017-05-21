/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief una maza
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Esta es una de las mazas que utilizan los reclutas enanos de Annufam. Est� construida en acero y a pesar de su tama�o resulta muy ligera. En la empu�adura puedes ver grabada la cabeza de un le�n.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_MAZA, 13, P_SIZE_GENERIC, M_ACERO);
	SetLong("Esta es una de las mazas que utilizan los reclutas enanos de Annufam. Est� construida en acero y a pesar de su tama�o resulta muy ligera. En la empu�adura puedes ver grabada la cabeza de un le�n.\n");
}
