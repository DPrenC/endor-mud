/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief una daga
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Es una daga pequeña y muy afilada que los reclutas de Annufam utilizan en sus entrenamientos. En la empuñadura puedes distinguir la cabeza de un león tallada.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_CUCHILLO, 3, P_SIZE_GENERIC, M_HIERRO);
	SetShort("una daga");
	AddId("daga");
	SetLong("Es una daga pequeña y muy afilada que los reclutas de Annufam utilizan en sus entrenamientos. En la empuñadura puedes distinguir la cabeza de un león tallada.\n");
	Set(P_GENDER, GENDER_FEMALE);
}
