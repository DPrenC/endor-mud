/* vi: set tabstop=4 */
/** @file botas_drow.c
	@brief unas botas negras.
	@author SimBuilder
	@version 1.00
	@date 2008-09-12

	Las típicas botas negras de un asesino drow. Son de tela para minimizar el ruido que podría delatar a su portador.

[T 21/02/2009: Cambiado el AC a 3
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

create()
{
	::create();
	SetStandard(AT_BOTAS, 3, P_SIZE_GENERIC, M_TELA);
	SetShort("unas botas negras");
	SetLong("Las típicas botas negras de un asesino drow. Son de tela para minimizar el ruido que podría delatar a su portador.\n");
	//replace_program();
	AddId(({"botas"}));
	AddAdjective(({"negras"}));
}
