/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief un látigo
	@author SimBuilder
	@version 1.00
	@date 2009-02-28
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(WT_LATIGO, 3, P_SIZE_GENERIC, M_CUERO);
	SetLong("Es un resistente látigo de cuero con refuerzos metálicos. De entre todos los látigos que has visto en Simauria este es sin duda el mejor. Quizás si lo sabes utilizar te sirva para algo más que atacar a tus enemigos.\n");
	AddId(({"latigo", "látigo resistente", "latigo resistente"}));
}
