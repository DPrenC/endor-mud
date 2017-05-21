/* vi: set tabstop=4 */
/** @file arena33.c
	@brief la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Sigues dando vueltas por la Arena de Annufam y poco a poco vas haciéndote una idea de como es este recinto: una gran explanada con una pequeña loma que ves al este, y aquí y allá montones de armas apiladas. Al sur sigues viendo la pared trasera del centro de adiestramiento y al oeste las murallas de la ciudad.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("bordeando");
	SetIntShort("la Arena");
	SetIntLong("Sigues dando vueltas por la Arena de Annufam y poco a poco vas haciéndote una idea de como es este recinto: una gran explanada con una pequeña loma que ves al este, y aquí y allá montones de armas apiladas. Al sur sigues viendo la pared trasera del centro de adiestramiento y al oeste las murallas de la ciudad.\n");
	AddExit("nordeste", "arena44");
	AddExit("este", "arena43");
	AddExit("sudeste", "arena42");
	AddExit("sur", "arena32");
	AddExit("suroeste", "arena22");
	AddLoma();
	AddParedLejos();
}
