/* vi: set tabstop=4 */
/** @file arena64.c
	@brief una loma
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Est�s llegando al extremo norte de la Arena de Annufam. La agitaci�n del entrenamiento parece que en esta zona se ve un tanto aminorada. Al suroeste tienes la cima de una loma y all� lejos, al sur, puedes ver la pared trasera del edificio. Hacia el este y muy cerca de ti se levantan las murallas de la ciudad, y en el resto de direcciones, m�s arena.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("rodeando");
	SetIntShort("una loma");
	SetIntLong("Est�s llegando al extremo norte de la Arena de Annufam. La agitaci�n del entrenamiento parece que en esta zona se ve un tanto aminorada. Al suroeste tienes la cima de una loma y all� lejos, al sur, puedes ver la pared trasera del edificio. Hacia el este y muy cerca de ti se levantan las murallas de la ciudad, y en el resto de direcciones, m�s arena.\n");
	AddExit("sudeste", "arena73");
	AddExit("sur", "arena63");
	AddExit("suroeste", "arena53");
	AddExit("oeste", "arena54");
	AddExit("noroeste", "arena55");
	AddLoma();
	AddParedLejos();
}
