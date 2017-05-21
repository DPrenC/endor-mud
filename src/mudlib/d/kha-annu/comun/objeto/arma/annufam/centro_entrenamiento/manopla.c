/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief una manopla
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Es una de las manoplas que los guerreros enanos de Annufam emplean en sus entrenamientos. Tiene la forma de un guante pero mucho más grande y además de hierro. En ella puedes ver grabada la cabeza de un león.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_MANOPLA, 7, P_SIZE_GENERIC, M_HIERRO);
	SetLong("Es una de las manoplas que los guerreros enanos de Annufam emplean en sus entrenamientos. Tiene la forma de un guante pero mucho más grande y además de hierro. En ella puedes ver grabada la cabeza de un león.\n");
}
