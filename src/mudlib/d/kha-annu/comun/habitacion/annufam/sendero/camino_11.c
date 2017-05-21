/* vi: set tabstop=4 */
/** @file camino_11.c
	@brief un pequeño sendero
	@author Admin
	@version 1.00
	@date 2009-04-15

Este es un tramo del sendero que lleva a Annufam, Puedes ver hacia el nordeste una escarpada pared que parece cortar el sendero.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetIntShort("un pequeño sendero");
	SetIntLong("Este es un tramo del sendero que lleva a Annufam, Puedes ver hacia el nordeste una escarpada pared que parece cortar el sendero.\n");
	AddExit("nordeste", "camino_12");
	AddExit("oeste", "camino_10");
	AddItem(PNJ_SENDERO_ANNUFAM("lobo_base"), REFRESH_DESTRUCT, random(2));
}
