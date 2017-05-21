/* vi: set tabstop=4 */
/** @file arena22.c
	@brief la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Hay restos de carne y salpicaduras de sangre por todas partes. Esto más que una academia militar parece un cruento campo de batalla en el que los enanos se baten a muerte contra sus enemigos los orcos, y te preguntas que te harían si en lugar de estar tan concentrados en sus entrenamientos decidiesen practicar contigo. Hacia el sur puedes ver la pared del centro de adiestramiento, hacia el noreste lo que parece una pequeña loma, y hacia el oeste las murallas de la ciudad.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("bordeando");
	SetIntShort("la Arena");
	SetIntLong("Hay restos de carne y salpicaduras de sangre por todas partes. Esto más que una academia militar parece un cruento campo de batalla en el que los enanos se baten a muerte contra sus enemigos los orcos, y te preguntas que te harían si en lugar de estar tan concentrados en sus entrenamientos decidiesen practicar contigo. Hacia el sur puedes ver la pared del centro de adiestramiento, hacia el noreste lo que parece una pequeña loma, y hacia el oeste las murallas de la ciudad.\n");
	AddExit("nordeste", "arena33");
	AddExit("este", "arena32");
	AddExit("sudeste", "arena31");
	AddExit("sur", "arena21");
	AddExit("suroeste", "arena11");
	AddParedLejos();
}
