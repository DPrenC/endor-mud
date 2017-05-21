/* vi: set tabstop=4 */
/** @file arena44.c
	@brief una loma
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Estás llegando al extremo norte de la Arena de Annufam. La agitación del entrenamiento parece que en esta zona se ve un tanto aminorada. Al sureste tienes la cima de una loma y allá lejos, al sur, puedes ver la pared trasera del edificio. Hacia el oeste y muy cerca de ti se levantan las murallas de la ciudad, y en el resto de direcciones, más arena.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("rodeando");
	SetIntShort("una loma");
	SetIntLong("Estás llegando al extremo norte de la Arena de Annufam. La agitación del entrenamiento parece que en esta zona se ve un tanto aminorada. Al sureste tienes la cima de una loma y allá lejos, al sur, puedes ver la pared trasera del edificio. Hacia el oeste y muy cerca de ti se levantan las murallas de la ciudad, y en el resto de direcciones, más arena.\n");
	AddExit("nordeste", "arena55");
	AddExit("este", "arena54");
	AddExit("sudeste", "arena53");
	AddExit("sur", "arena43");
	AddExit("suroeste", "arena33");
	AddLoma();
	AddParedLejos();
}
