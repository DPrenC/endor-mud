/* vi: set tabstop=4 */
/** @file camino_05.c
	@brief un peque�o sendero
	@author Admin
	@version 1.00
	@date 2009-04-15

Este es el sendero que lleva hasta la ciudadela de Annufam. Hacia el oeste est� el puente de piedra que permite atravesar el r�o Kilok y hacia el este contin�a el sendero.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetIntShort("un peque�o sendero");
	SetIntLong("Este es el sendero que lleva hasta la ciudadela de Annufam. Hacia el oeste est� el puente de piedra que permite atravesar el r�o Kilok y hacia el este contin�a el sendero.\n");
	AddExit("este", "camino_06");
	AddExit("noroeste", "camino_04");
}
