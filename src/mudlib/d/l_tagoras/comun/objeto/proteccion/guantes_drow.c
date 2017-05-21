/* vi: set tabstop=4 */
/** @file armadura_test.c
	@brief unos guantes negros
	@author SimBuilder
	@version 1.00
	@date 2008-09-12

	Unos guantes de cuero negro que evitan raspaduras accidentales al manejar objetos cortantes.

[T] 21/03/2009: Cambiado el AC a 3.
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	//replace_program();
	SetStandard(AT_GUANTES, 3, P_SIZE_GENERIC, M_CUERO);
	SetShort("unos guantes negros");
	SetLong("Unos guantes de cuero negro que evitan raspaduras accidentales al manejar objetos cortantes.\n");
	AddAdjective(({"negros"}));
}
