/* vi: set tabstop=4 */
/** @file armadura_test.c
	@brief unos pantalones negros.
	@author SimBuilder
	@version 1.00
	@date 2008-09-12

	Unos pantalones de tela negro usados normalmente por gente que quiere pasar desapercibida en lugares oscuros.

[T] 21/03/2009: Cambiado el AC a 6.
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	//replace_program();
	SetStandard(AT_PANTALONES, 6, P_SIZE_GENERIC, M_TELA);
	SetShort("unos pantalones negros");
	SetLong("Unos pantalones de tela negro usados normalmente por gente que quiere pasar desapercibida en lugares oscuros.\n");
	AddId(({"pantalones"}));
	AddAdjective(({"negros"}));
}
