/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief una lanza
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Se trata de una lanza de hierro forjado que parece bastante contundente. La empuñadura es de madera y en ella hay un asidero para poderla agarrar con las dos manos en caso de necesidad. En su filo puedes observar grabada la cabeza de un león.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_LANZA, 10, P_SIZE_GENERIC, M_HIERRO);
	SetLong("Se trata de una lanza de hierro forjado que parece bastante contundente. La empuñadura es de madera y en ella hay un asidero para poderla agarrar con las dos manos en caso de necesidad. En su filo puedes observar grabada la cabeza de un león.\n");
}
