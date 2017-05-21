/* vi: set tabstop=4 */
/** @file armadura_test.c
	@brief un mono azul
	@author SimBuilder
	@version 1.00
	@date 2009-02-08

	Es un mono azul que suelen llevar los barrenderos.

[T] 21/02/2009: Cambiado el AC a 2.
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(AT_CORAZA, 2, P_SIZE_GENERIC, M_TELA);
	SetShort("un mono azul");
	SetLong("Es un mono azul que suelen llevar los barrenderos.\n");
	AddId(({"mono"}));
	AddAdjective(({"azul"}));
	SetWeight(3000);
	Set(P_GENDER, GENDER_MALE);
}
