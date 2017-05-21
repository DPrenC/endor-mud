/* vi: set tabstop=4 */
/** @file arena31.c
	@brief la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Al sur tienes la pared del edificio y ante ti se contempla el caos de la Arena de Annufam. Cuerpos heridos, enanos con las hachas alzadas gritando, armas tiradas por el suelo... y mucha sangre. Nunca pensaste que un entrenamiento pudiera desencadenar tanta locura y destrucción.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena_trasera.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("bordeando");
	SetIntShort("la Arena");
	SetIntLong("Al sur tienes la pared del edificio y ante ti se contempla el caos de la Arena de Annufam. Cuerpos heridos, enanos con las hachas alzadas gritando, armas tiradas por el suelo... y mucha sangre. Nunca pensaste que un entrenamiento pudiera desencadenar tanta locura y destrucción.\n");
	AddExit("norte", "arena32");
	AddExit("nordeste", "arena42");
	AddExit("este", "arena41");
	AddExit("oeste", "arena21");
	AddExit("noroeste", "arena22");
}
