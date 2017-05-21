/* vi: set tabstop=4 */
/** @file camino_02.c
	@brief el río Kilok
	@author Admin
	@version 1.00
	@date 2009-04-15

Este es el puente de piedra que atraviesa el río Kilok.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetPreIntShort("sobre");
	SetIntShort("el río Kilok");
	SetIntLong("Este es el puente de piedra que atraviesa el río Kilok.\n");
	AddDetail("puente", "Es un puente de piedra de un solo ojo construido sobre el río Kilok.\n");
	AddDetail(({"río", "rio"}), "Es el río Gaut-Kilok que nace en las montañas de Kha-annu.\n");
	SetIntNoise("Oyes el ruido del agua que discurre bajo el puente.\n");
	AddExit("este", "camino_03");
	AddExit("oeste", "camino_01");
}
