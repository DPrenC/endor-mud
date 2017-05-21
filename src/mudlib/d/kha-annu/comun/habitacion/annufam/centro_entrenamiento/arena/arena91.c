/* vi: set tabstop=4 */
/** @file arena91.c
	@brief el extremo sudeste de la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Estás en el extremo sudeste de la Arena. Aquí es donde los enanos de Annufam practican las habilidades de combate que han aprendido en el centro. Hacia el sur tienes la pared del edificio y hacia el este las murallas de la ciudad sobre la que se encuentran los arqueros, los vigías y los patrulleros que la defienden.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena_trasera.c");

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("el extremo sudeste de la Arena");
	SetIntLong("Estás en el extremo sudeste de la Arena. Aquí es donde los enanos de Annufam practican las habilidades de combate que han aprendido en el centro. Hacia el sur tienes la pared del edificio y hacia el este las murallas de la ciudad sobre la que se encuentran los arqueros, los vigías y los patrulleros que la defienden.\n");
	AddExit("oeste", "arena81");
	AddExit("noroeste", "arena82");
}
