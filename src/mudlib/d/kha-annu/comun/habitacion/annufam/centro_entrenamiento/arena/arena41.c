/* vi: set tabstop=4 */
/** @file arena41.c
	@brief la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Aquí parece que la vorágine del entrenamiento se calma. Los enanos siguen armados hasta los dientes pero en lugar de golpearse entre ellos y desfilar en actitud militar, los ves un poco más relajados alrededor de un barril.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena_trasera.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("bordeando");
	SetIntShort("la Arena");
	SetIntLong("Aquí parece que la vorágine del entrenamiento se calma. Los enanos siguen armados hasta los dientes pero en lugar de golpearse entre ellos y desfilar en actitud militar, los ves un poco más relajados alrededor de un barril.\n");
	AddExit("norte", "arena42");
	AddExit("nordeste", "arena52");
	AddExit("este", "arena51");
	AddExit("oeste", "arena31");
	AddExit("noroeste", "arena32");
	AddItem(OTRO_ANNUFAM("barril"), REFRESH_MOVE_HOME);
}
