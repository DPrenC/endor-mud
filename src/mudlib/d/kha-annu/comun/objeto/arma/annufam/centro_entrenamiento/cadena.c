/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief una cadena
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Es una cadena larga y con eslabones muy gordos que los reclutas de Annufam emplean en sus entrenamientos. Tiene una empuñadura metálica en la que hay grabada la cabeza de un león.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_CADENA, 5, P_SIZE_GENERIC, M_HIERRO);
	SetLong("Es una cadena larga y con eslabones muy gordos que los reclutas de Annufam emplean en sus entrenamientos. Tiene una empuñadura metálica en la que hay grabada la cabeza de un león.\n");
}
