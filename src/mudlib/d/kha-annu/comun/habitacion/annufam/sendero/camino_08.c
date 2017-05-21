/* vi: set tabstop=4 */
/** @file camino_08.c
	@brief un peque�o sendero
	@author Admin
	@version 1.00
	@date 2009-04-15

Es un tramo m�s del sendero que permite llegar hasta Annufam.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetIntShort("un peque�o sendero");
	SetIntLong("Es un tramo m�s del sendero que permite llegar hasta Annufam.\n");
	AddExit("nordeste", "camino_09");
	AddExit("suroeste", "camino_07");
}
