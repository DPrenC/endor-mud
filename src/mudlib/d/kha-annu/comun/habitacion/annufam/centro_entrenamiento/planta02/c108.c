/* vi: set tabstop=4 */
/** @file c108.c
	@brief un pasillo
	@author SimBuilder
	@version 1.00
	@date 2009-02-27

Los pasillos del centro de adiestramiento de guerreros enanos son bastante oscuros. Solo hay alguna antorcha y alguna lámpara pero no es que ofrezcan mucha claridad. Al norte y al sur hay puertas, y hacia al este y el oeste el pasillo continua.
*/

#include "./path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_pasillo");

create() {
	::create();
	SetIntShort("un pasillo");
	SetIntLong("Los pasillos del centro de adiestramiento de guerreros enanos son bastante oscuros. Solo hay alguna antorcha y alguna lámpara pero no es que ofrezcan mucha claridad. Al norte y al sur hay puertas, y hacia al este y el oeste el pasillo continua.\n");
	AddExit("norte", "c107");
	AddDoor("norte");
	AddExit("este", "c111");
	AddExit("sur", "c109");
	AddDoor("sur");
	AddExit("oeste", "c105");
}
