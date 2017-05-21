/* vi: set tabstop=4 */
/** @file arena72.c
	@brief la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

El entrenamiento en Annufam se divide en dos partes: en el interior del edificio los guerreros enanos aprenden los rudimentos básicos del arte de la guerra, y en la Arena ponen en práctica esas habilidades en simulaciones de ataque y en combates cuerpo a cuerpo. De hecho, puedes ver algún enano herido por sus propios compañeros llevado rápidamente al interior del edificio que tienes al sur. Hacia el noroeste hay una pequeña loma.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("la Arena");
	SetIntLong("El entrenamiento en Annufam se divide en dos partes: en el interior del edificio los guerreros enanos aprenden los rudimentos básicos del arte de la guerra, y en la Arena ponen en práctica esas habilidades en simulaciones de ataque y en combates cuerpo a cuerpo. De hecho, puedes ver algún enano herido por sus propios compañeros llevado rápidamente al interior del edificio que tienes al sur. Hacia el noroeste hay una pequeña loma.\n");
	AddExit("norte", "arena73");
	AddExit("este", "arena82");
	AddExit("sudeste", "arena81");
	AddExit("sur", "arena71");
	AddExit("suroeste", "arena61");
	AddExit("oeste", "arena62");
	AddExit("noroeste", "arena63");
	AddLoma();
	AddParedLejos();
}
