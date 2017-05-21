/* vi: set tabstop=4 */
/** @file c117.c
	@brief un pasillo
	@author SimBuilder
	@version 1.00
	@date 2009-02-27

Estás al principio de uno de los pasillos del centro de adiestramiento de reclutas enanos de Annufam. Justo al oeste tienes una salida a las escaleras, y al este el pasillo se prolonga varios metros. Al norte y al sur hay puertas a las habitaciones de los reclutas.
*/

#include "./path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_pasillo");

create() {
	::create();
	SetIntShort("un pasillo");
	SetIntLong("Estás al principio de uno de los pasillos del centro de adiestramiento de reclutas enanos de Annufam. Justo al oeste tienes una salida a las escaleras, y al este el pasillo se prolonga varios metros. Al norte y al sur hay puertas a las habitaciones de los reclutas.\n");
	AddExit("norte", "c116");
	AddDoor("norte");
	AddExit("este", "c120");
	AddExit("sur", "c118");
	AddDoor("sur");
	AddExit("oeste", "c114");
}
