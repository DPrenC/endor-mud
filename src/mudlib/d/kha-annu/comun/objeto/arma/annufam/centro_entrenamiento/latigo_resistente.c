/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief un l�tigo
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
	SetLong("Es un resistente l�tigo de cuero con refuerzos met�licos. De entre todos los l�tigos que has visto en Simauria este es sin duda el mejor. Quiz�s si lo sabes utilizar te sirva para algo m�s que atacar a tus enemigos.\n");
	AddId(({"latigo", "l�tigo resistente", "latigo resistente"}));
}
