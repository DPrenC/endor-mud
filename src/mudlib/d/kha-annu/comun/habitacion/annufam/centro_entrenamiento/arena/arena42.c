/* vi: set tabstop=4 */
/** @file arena42.c
	@brief una loma
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Observas como los guerreros enanos de Annufam forman en perfectas escuadras, contemplas como blanden sus armas, te impresionas con el fulgor de su mirada, te sorprende la disciplina que muestran ante sus superiores, y sabes que Annufam es la más perfecta escuela militar que jamás has conocido. Hacia el sur puedes ver la pared del edificio y hacia el noreste subirás a una pequeña loma.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetPreIntShort("rodeando");
	SetIntShort("una loma");
	SetIntLong("Observas como los guerreros enanos de Annufam forman en perfectas escuadras, contemplas como blanden sus armas, te impresionas con el fulgor de su mirada, te sorprende la disciplina que muestran ante sus superiores, y sabes que Annufam es la más perfecta escuela militar que jamás has conocido. Hacia el sur puedes ver la pared del edificio y hacia el noreste subirás a una pequeña loma.\n");
	AddExit("norte", "arena43");
	AddExit("nordeste", "arena53");
	AddExit("este", "arena52");
	AddExit("sudeste", "arena51");
	AddExit("sur", "arena41");
	AddExit("suroeste", "arena31");
	AddExit("oeste", "arena32");
	AddExit("noroeste", "arena33");
	AddLoma();
	AddParedLejos();
}
