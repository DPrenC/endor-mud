/* vi: set tabstop=4 */
/** @file camino_05.c
	@brief un pequeño sendero
	@author Admin
	@version 1.00
	@date 2009-04-15

Este es el sendero que lleva hasta la ciudadela de Annufam. Hacia el oeste está el puente de piedra que permite atravesar el río Kilok y hacia el este continúa el sendero.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetIntShort("un pequeño sendero");
	SetIntLong("Este es el sendero que lleva hasta la ciudadela de Annufam. Hacia el oeste está el puente de piedra que permite atravesar el río Kilok y hacia el este continúa el sendero.\n");
	AddExit("este", "camino_06");
	AddExit("noroeste", "camino_04");
}
