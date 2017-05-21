/* vi: set tabstop=4 */
/** @file camino_09.c
	@brief un pequeño sendero
	@author Admin
	@version 1.00
	@date 2009-04-15

Es otro recodo en el sendero que va hasta Annufam, la ciudadela guerrera.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetIntShort("un pequeño sendero");
	SetIntLong("Es otro recodo en el sendero que va hasta Annufam, la ciudadela guerrera.\n");
	AddExit("sudeste", "camino_10");
	AddExit("suroeste", "camino_08");
}
