/* vi: set tabstop=4 */
/** @file camino_07.c
	@brief un pequeño sendero
	@author Admin
	@version 1.00
	@date 2009-04-15

Es un recodo en el sendero que lleva a Annufam, la ciudadela.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetIntShort("un pequeño sendero");
	SetIntLong("Es un recodo en el sendero que lleva a Annufam, la ciudadela.\n");
	AddExit("nordeste", "camino_08");
	AddExit("noroeste", "camino_06");
}
