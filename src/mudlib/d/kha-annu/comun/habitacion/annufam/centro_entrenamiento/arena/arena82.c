/* vi: set tabstop=4 */
/** @file arena82.c
	@brief la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Hay restos de carne y salpicaduras de sangre por todas partes. Esto más que una academia militar parece un cruento campo de batalla en el que los enanos se baten a muerte contra sus enemigos los orcos, y te preguntas que te harían si en lugar de estar tan concentrados en sus entrenamientos decidiesen practicar contigo. Hacia el sur puedes ver la pared del centro de adiestramiento, hacia el noroeste lo que parece una pequeña loma, y hacia el este las murallas de la ciudad.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("bordeando");
	SetIntShort("la Arena");
	SetIntLong("Hay restos de carne y salpicaduras de sangre por todas partes. Esto más que una academia militar parece un cruento campo de batalla en el que los enanos se baten a muerte contra sus enemigos los orcos, y te preguntas que te harían si en lugar de estar tan concentrados en sus entrenamientos decidiesen practicar contigo. Hacia el sur puedes ver la pared del centro de adiestramiento, hacia el noroeste lo que parece una pequeña loma, y hacia el este las murallas de la ciudad.\n");
	AddExit("sudeste", "arena91");
	AddExit("sur", "arena81");
	AddExit("suroeste", "arena71");
	AddExit("oeste", "arena72");
	AddExit("noroeste", "arena73");
	AddParedLejos();
}
