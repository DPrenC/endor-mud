/* vi: set tabstop=4 */
/** @file arena81.c
	@brief la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Estos enanos de Annufam son grandes guerreros, o por lo menos as� lo aparentan las salpicaduras de sangre que ves por el suelo. Imaginas que la puesta en pr�ctica de sus habilidades no tiene l�mites, y sospechas que si tienen que matarse entre si, lo hacen sin excesiva preocupaci�n.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena_trasera.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("bordeando");
	SetIntShort("la Arena");
	SetIntLong("Estos enanos de Annufam son grandes guerreros, o por lo menos as� lo aparentan las salpicaduras de sangre que ves por el suelo. Imaginas que la puesta en pr�ctica de sus habilidades no tiene l�mites, y sospechas que si tienen que matarse entre si, lo hacen sin excesiva preocupaci�n.\n");
	AddExit("norte", "arena82");
	AddExit("este", "arena91");
	AddExit("oeste", "arena71");
	AddExit("noroeste", "arena72");
}
