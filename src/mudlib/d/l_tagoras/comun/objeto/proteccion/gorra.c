/* vi: set tabstop=4 */
/** @file armadura_test.c
	@brief una gorra
	@author SimBuilder
	@version 1.00
	@date 2009-02-08

	Una gorra del gremio de barrendero. Lleva una insignia.

[T] 21/03/2009: Cambiado el AC a 1
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(AT_CASCO, 1, P_SIZE_GENERIC, M_CUERO);
	SetShort("una gorra");
	SetLong("Una gorra del gremio de barrendero. Lleva una insignia.\n");
	AddId(({"gorra"}));
	SetWeight(300);
	Set(P_GENDER, GENDER_FEMALE);
	AddSubDetail(({"insignia"}),"Es la insignia del gremio de barrenderos.\n");
}
