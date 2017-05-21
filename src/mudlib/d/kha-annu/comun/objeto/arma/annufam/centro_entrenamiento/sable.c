/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief un sable
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Los sables que los reclutas de Annufam emplean son diferentes a los que has visto en Simauria. Son igual de afilados, eso sí, pero totalmente rectos y su empuñadura se asemeja a la cabeza de un león.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_ESPADA, 12, P_SIZE_GENERIC, M_HIERRO);
	SetShort("un sable");
	SetLong("Los sables que los reclutas de Annufam emplean son diferentes a los que has visto en Simauria. Son igual de afilados, eso sí, pero totalmente rectos y su empuñadura se asemeja a la cabeza de un león.\n");
	Set(P_GENDER, GENDER_MALE);
	AddId("sable");
}
