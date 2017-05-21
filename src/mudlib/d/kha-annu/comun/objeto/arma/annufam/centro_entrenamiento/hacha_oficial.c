/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief un hacha de oficial
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Se trata de un hacha de doble filo fabricada en mithril y que parece mucho más resistente que cualquier otra de las que has visto en Simauria.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_HACHA, 12, P_SIZE_GENERIC, M_MITHRIL);
	SetShort("un hacha de oficial");
	SetLong("Se trata de un hacha de doble filo fabricada en mithril y que parece mucho más resistente que cualquier otra de las que has visto en Simauria.\n");
}
