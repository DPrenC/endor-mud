/* vi: set tabstop=4 */
/** @file camino_02.c
	@brief el r�o Kilok
	@author Admin
	@version 1.00
	@date 2009-04-15

Este es el puente de piedra que atraviesa el r�o Kilok.
*/

#include "./path.h"

inherit HAB_CAMINO_ANNUFAM("sendero_base");

create() {
	::create();
	SetLocate("Camino Annufam");
	SetPreIntShort("sobre");
	SetIntShort("el r�o Kilok");
	SetIntLong("Este es el puente de piedra que atraviesa el r�o Kilok.\n");
	AddDetail("puente", "Es un puente de piedra de un solo ojo construido sobre el r�o Kilok.\n");
	AddDetail(({"r�o", "rio"}), "Es el r�o Gaut-Kilok que nace en las monta�as de Kha-annu.\n");
	SetIntNoise("Oyes el ruido del agua que discurre bajo el puente.\n");
	AddExit("este", "camino_03");
	AddExit("oeste", "camino_01");
}
