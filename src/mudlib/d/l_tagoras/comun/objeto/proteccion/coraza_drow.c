/* vi: set tabstop=4 */
/** @file armadura_test.c
	@brief una coraza negra
	@author SimBuilder
	@version 1.00
	@date 2008-09-12

	Una coraza de cuero negro que cubre el cuerpo y limita su exposición a la intemperie.

[T] 20/03/2009: Cambiado AC a 10
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	//replace_program();
	SetStandard(AT_CORAZA, 10, P_SIZE_GENERIC, M_CUERO);
	SetShort("una coraza negra");
	SetLong("Una coraza de cuero negro que cubre el cuerpo y limita su exposición a la intemperie.\n");
}
