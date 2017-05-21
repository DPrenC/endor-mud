/* vi: set tabstop=4 */
/** @file camino_10.c
	@brief un peque�o sendero
	@author Admin
	@version 1.00
	@date 2009-04-15

El sendero a Annufam discurre por un tramo monta�oso de Kha-annu.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetIntShort("un peque�o sendero");
	SetIntLong("El sendero a Annufam discurre por un tramo monta�oso de Kha-annu.\n");
	AddExit("este", "camino_11");
	AddExit("noroeste", "camino_09");
	AddItem(PNJ_SENDERO_ANNUFAM("lobo_base"), REFRESH_DESTRUCT, random(2));
}
