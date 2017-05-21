/* vi: set tabstop=4 */
/** @file c111.c
	@brief un pasillo
	@author SimBuilder
	@version 1.00
	@date 2009-02-27

Este es el inicio de uno de los pasillos del centro de adiestramiento de reclutas enanos de Annufam. Justo al este tienes una salida a las escaleras, y al oeste el pasillo se prolonga varios metros. Al norte y al sur hay puertas a las habitaciones de los reclutas.
*/

#include "./path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_pasillo");

create() {
	::create();
	SetIntShort("un pasillo");
	SetIntLong("Este es el inicio de uno de los pasillos del centro de adiestramiento de reclutas enanos de Annufam. Justo al este tienes una salida a las escaleras, y al oeste el pasillo se prolonga varios metros. Al norte y al sur hay puertas a las habitaciones de los reclutas.\n");
	AddExit("norte", "c110");
	AddDoor("norte");
	AddExit("este", "c114");
	AddExit("sur", "c112");
	AddDoor("sur");
	AddExit("oeste", "c108");
}
