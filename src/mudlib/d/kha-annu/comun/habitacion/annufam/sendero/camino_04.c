/* vi: set tabstop=4 */
/** @file camino_04.c
	@brief la entrada este del puente
	@author Admin
	@version 1.00
	@date 2009-04-15

Esta es la entrada este del puente que atraviesa el río Kilok y que permite seguir el camino hasta la ciudadela de Annufam.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetIntShort("la entrada este del puente");
	SetIntLong("Esta es la entrada este del puente que atraviesa el río Kilok y que permite seguir el camino hasta la ciudadela de Annufam.\n");
	AddDetail("puente", "Es un puente de piedra de un sólo arco que cruza el río Kilok.\n");
	SetIntNoise("Oyes el ruido del agua que discurre bajo el puente.\n");
	AddExit("sudeste", "camino_05");
	AddExit("oeste", "camino_03");
}
