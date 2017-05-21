/* vi: set tabstop=4 */
/** @file arena62.c
	@brief una loma
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Observas como los guerreros enanos de Annufam forman en perfectas escuadras, contemplas como blanden sus armas, te impresionas con el fulgor de su mirada, te sorprende la disciplina que muestran ante sus superiores, y sabes que Annufam es la más perfecta escuela militar que jamás has conocido. Hacia el sur puedes ver la pared del edificio y hacia el noroeste subirás a una pequeña loma.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("rodeando");
	SetIntShort("una loma");
	SetIntLong("Observas como los guerreros enanos de Annufam forman en perfectas escuadras, contemplas como blanden sus armas, te impresionas con el fulgor de su mirada, te sorprende la disciplina que muestran ante sus superiores, y sabes que Annufam es la más perfecta escuela militar que jamás has conocido. Hacia el sur puedes ver la pared del edificio y hacia el noroeste subirás a una pequeña loma.\n");
	AddExit("norte", "arena63");
	AddExit("nordeste", "arena73");
	AddExit("este", "arena72");
	AddExit("sudeste", "arena71");
	AddExit("sur", "arena61");
	AddExit("suroeste", "arena51");
	AddExit("oeste", "arena52");
	AddExit("noroeste", "arena53");
	AddLoma();
	AddParedLejos();
}
