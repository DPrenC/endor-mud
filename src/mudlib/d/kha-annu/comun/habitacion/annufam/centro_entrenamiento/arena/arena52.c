/* vi: set tabstop=4 */
/** @file arena52.c
	@brief los pies de una loma
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Avanzas por la Arena de Annufam y la sensación de adentrarte en un campo de batalla se va apoderando de ti poco a poco. Al sur has dejado el centro de adiestramiento y hacia el norte observas una pequeña loma sobre la que ves algunos enanos desplegando sus habilidades de guerrero. Rodeando la arena puedes ver como las murallas de la ciudad protegen también esta parte del centro.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("a");
	SetIntShort("los pies de una loma");
	SetIntLong("Avanzas por la Arena de Annufam y la sensación de adentrarte en un campo de batalla se va apoderando de ti poco a poco. Al sur has dejado el centro de adiestramiento y hacia el norte observas una pequeña loma sobre la que ves algunos enanos desplegando sus habilidades de guerrero. Rodeando la arena puedes ver como las murallas de la ciudad protegen también esta parte del centro.\n");
	AddExit("norte", "arena53");
	AddExit("nordeste", "arena63");
	AddExit("este", "arena62");
	AddExit("sudeste", "arena61");
	AddExit("sur", "arena51");
	AddExit("suroeste", "arena41");
	AddExit("oeste", "arena42");
	AddExit("noroeste", "arena43");
	AddLoma();
	AddParedLejos();
}
