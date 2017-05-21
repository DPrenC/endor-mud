/* vi: set tabstop=4 */
/** @file arena21.c
	@brief la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Estos enanos de Annufam son grandes guerreros, o por lo menos así lo aparentan las salpicaduras de sangre que ves por el suelo. Imaginas que la puesta en práctica de sus habilidades no tiene límites, y sospechas que si tienen que matarse entre si, lo hacen sin excesiva preocupación.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena_trasera.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("bordeando");
	SetIntShort("la Arena");
	SetIntLong("Estos enanos de Annufam son grandes guerreros, o por lo menos así lo aparentan las salpicaduras de sangre que ves por el suelo. Imaginas que la puesta en práctica de sus habilidades no tiene límites, y sospechas que si tienen que matarse entre si, lo hacen sin excesiva preocupación.\n");
	AddExit("norte", "arena22");
	AddExit("nordeste", "arena32");
	AddExit("este", "arena31");
	AddExit("oeste", "arena11");
}
