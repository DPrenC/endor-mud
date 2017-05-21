/* vi: set tabstop=4 */
/** @file arena73.c
	@brief la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Sigues dando vueltas por la Arena de Annufam y poco a poco vas haciéndote una idea de como es este recinto: una gran explanada con una pequeña loma que ves al oeste, y aquí y allá montones de armas apiladas. Al sur sigues viendo la pared trasera del centro de adiestramiento y al este las murallas de la ciudad.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("bordeando");
	SetIntShort("la Arena");
	SetIntLong("Sigues dando vueltas por la Arena de Annufam y poco a poco vas haciéndote una idea de como es este recinto: una gran explanada con una pequeña loma que ves al oeste, y aquí y allá montones de armas apiladas. Al sur sigues viendo la pared trasera del centro de adiestramiento y al este las murallas de la ciudad.\n");
	AddExit("sudeste", "arena82");
	AddExit("sur", "arena72");
	AddExit("suroeste", "arena62");
	AddExit("oeste", "arena63");
	AddExit("noroeste", "arena64");
	AddLoma();
	AddParedLejos();
}
