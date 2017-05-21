/* vi: set tabstop=4 */
/** @file katana_drow.c
	@brief una katana drow
	@author SimBuilder
	@version 1.00
	@date 2008-09-12

	Estas katanas drows son famosas por su afilada hoja y por la facilidad con la que traspasen la carne de la victima. Sientes que su filo es letal.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	//replace_program();
	SetStandard(WT_ESGRIMA, 11, P_SIZE_GENERIC, M_ACERO);
	SetShort("una katana drow");
	SetLong("Estas katanas drows son famosas por su afilada hoja y por la facilidad con la que traspasen la carne de la victima. Sientes que su filo es letal.\n");
	AddId(({"katana"}));
	AddAdjective(({"drow"}));
	SetWeight(4800);
	SetValue(2750);
	Set(P_GENDER, GENDER_FEMALE);
	SetNumberHands(2);
	AddSubDetail(({"filo"}),"El filo es acerado y refulge cuando la luz incide sobre la hoja.\n");
}
