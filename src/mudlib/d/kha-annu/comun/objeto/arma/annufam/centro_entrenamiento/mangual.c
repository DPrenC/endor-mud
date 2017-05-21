/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief un mangual
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Es uno de los manguales que utilizan los reclutas de Annufam en sus entrenamientos. Está formado por una empuñadura unida a una cadena de hierro rematada con una gran bola de acero. En la empuñadura puedes ver tallada la cabeza de un león.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_MANGUAL, 13, P_SIZE_GENERIC, M_ACERO);
	SetLong("Es uno de los manguales que utilizan los reclutas de Annufam en sus entrenamientos. Está formado por una empuñadura unida a una cadena de hierro rematada con una gran bola de acero. En la empuñadura puedes ver tallada la cabeza de un león.\n");
}
