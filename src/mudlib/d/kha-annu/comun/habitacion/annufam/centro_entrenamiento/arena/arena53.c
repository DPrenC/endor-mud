/* vi: set tabstop=4 */
/** @file arena53.c
	@brief una loma
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Has subido a una pequeña loma en el centro de la Arena de Annufam. Los enanos aprovechan este promontorio para realizar prácticas de combate en terrenos escarpados. En el suelo hay cantidad de rocas apiladas creando obstáculos que les ves sortear con destreza. Hacia el sur contemplas la pared del edificio y hacia el resto de direcciones, más entrenamientos enanos.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("una loma");
	SetIntLong("Has subido a una pequeña loma en el centro de la Arena de Annufam. Los enanos aprovechan este promontorio para realizar prácticas de combate en terrenos escarpados. En el suelo hay cantidad de rocas apiladas creando obstáculos que les ves sortear con destreza. Hacia el sur contemplas la pared del edificio y hacia el resto de direcciones, más entrenamientos enanos.\n");
	AddDetail(({"roca", "rocas"}), "Son varios montones de rocas que los enanos han distribuido sobre la loma de manera estratégica. Un grupo de guerreros está protegiéndose detrás suyo mientras que otro, menos numeroso, intenta tomar la posición comandados por un maestro guerrero.\n");
	AddExit("norte", "arena54");
	AddExit("nordeste", "arena64");
	AddExit("este", "arena63");
	AddExit("sudeste", "arena62");
	AddExit("sur", "arena52");
	AddExit("suroeste", "arena42");
	AddExit("oeste", "arena43");
	AddExit("noroeste", "arena44");
	AddLoma();
	AddParedLejos();
}
