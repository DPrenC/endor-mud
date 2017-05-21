/* vi: set tabstop=4 */
/** @file collar_darwen.c
	@brief el collar de Darwen
	@author Admin
	@version 1.00
	@date 2009-04-28

Es un fino collar de perlas blancas que Tagoras regaló a Darwen en su aniversario.
*/

#include "path.h"
#include <colours.h>
#include <properties.h>

inherit BASE_ITEM_DARWEN;

create() {
	::create();
	SetShort("el collar de Darwen");
	SetLong("Es un fino collar de perlas "+TC_WHITE+"blancas"+TC_NORMAL+" que Tagoras regaló a Darwen en su aniversario.\n");
	SetIds(({"collar", "collar_darwen"}));
	AddSubDetail(({"perla", "perlas"}), "Las perlas son esferas cuasi perfectas formada por nácar. Estas en particular son de color "+TC_WHITE+"blanco"+TC_NORMAL+".\n");
	SetMaterial(M_ESPECIAL);
	SetValue(15000);
	SetWeight(300);
	SetNoise("Las perlas hacen un ruido particular al entrechocar entre sí.\n");
}
