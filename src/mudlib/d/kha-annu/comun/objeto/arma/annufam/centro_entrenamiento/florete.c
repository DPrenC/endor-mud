/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief un florete
	@author SimBuilder
	@version 1.00
	@date 2009-02-28

	Se trata del florete oficial de los reclutas de Annufam. Est� fabricado en acero muy muy igero y flexible, pero a pesar  de ello, no te cabe duda de que en las manos adecuadas es un arma de lo m�s mort�fera. En la empu�adura hay grabada la cabeza de un le�n.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_ESGRIMA, 9, P_SIZE_GENERIC, M_HIERRO);
	SetLong("Se trata del florete oficial de los reclutas de Annufam. Est� fabricado en acero muy muy ligero y flexible, pero a pesar de ello, no te cabe duda de que en las manos adecuadas es un arma de lo m�s mort�fera. En la empu�adura hay grabada la cabeza de un le�n.\n");
	AddId("florete");
}
