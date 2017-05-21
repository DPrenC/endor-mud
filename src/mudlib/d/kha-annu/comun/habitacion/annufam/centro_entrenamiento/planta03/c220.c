/* vi: set tabstop=4 */
/** @file c220.c
	@brief 
	@author SimBuilder
	@version 1.00
	@date 2009-03-07


*/

#include "./path.h"

inherit HAB_TERCERA_ANNUFAM("base_pasillo.c");

create() {
	::create();
	SetLocate("Annufam");
    SetIntShort("un pasillo");
    SetIntLong("Los pasillos del centro de adiestramiento de guerreros enanos son bastante oscuros. Solo hay alguna antorcha y alguna l�mpara pero no es que ofrezcan mucha claridad. Al norte y al sur hay puertas, y hacia al este y el oeste el pasillo continua.\n");
	AddExit("norte", "c219");
	AddDoor("norte");
	AddExit("este", "c223");
	AddExit("sur", "c221");
	AddDoor("sur");
	AddExit("oeste", "c217");
}
