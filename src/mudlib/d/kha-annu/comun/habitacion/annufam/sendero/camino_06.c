/* vi: set tabstop=4 */
/** @file camino_06.c
	@brief un pequeño sendero
	@author Admin
	@version 1.00
	@date 2009-04-15

Este es el sendero que lleva hasta la ciudadela fortificada de Annufam.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetIntShort("un pequeño sendero");
	SetIntLong("Este es el sendero que lleva hasta la ciudadela fortificada de Annufam.\n");
	AddExit("sudeste", "camino_07");
	AddExit("oeste", "camino_05");
}
