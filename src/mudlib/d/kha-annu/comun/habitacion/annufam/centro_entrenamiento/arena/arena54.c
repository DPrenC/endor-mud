/* vi: set tabstop=4 */
/** @file arena54.c
	@brief los pies de una loma
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Estás a los pies de una pequeña loma que abarca gran parte del centro de la Arena. A su alrededor y sobre ella puedes ver, dirigidos por uno de los maestros guerreros, desplegarse a algunos enanos en lo que parece un ataque organizado a lo más alto del promontorio. Hacia el este y el oeste puedes bordear la loma, pero si prefieres intentar subir tendrás que ir hacia el sur.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("a");
	SetIntShort("los pies de una loma");
	SetIntLong("Estás a los pies de una pequeña loma que abarca gran parte del centro de la Arena. A su alrededor y sobre ella puedes ver, dirigidos por uno de los maestros guerreros, desplegarse a algunos enanos en lo que parece un ataque organizado a lo más alto del promontorio. Hacia el este y el oeste puedes bordear la loma, pero si prefieres intentar subir tendrás que ir hacia el sur.\n");
	AddDetail(({"pared", "paredes"}), "A esta distancia ya no puedes ver más que los pisos superiores del edificio ya que la loma se interpone en tu mirada.\n");
	AddExit("norte", "arena55");
	AddExit("este", "arena64");
	AddExit("sudeste", "arena63");
	AddExit("sur", "arena53");
	AddExit("suroeste", "arena43");
	AddExit("oeste", "arena44");
	AddLoma();
}
