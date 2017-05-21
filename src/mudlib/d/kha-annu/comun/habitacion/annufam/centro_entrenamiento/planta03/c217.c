/* vi: set tabstop=4 */
/** @file c217.c
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
    SetIntLong("Estás en un pasillo del segundo piso del centro de adiestramiento de reclutas enanos de Annufam. Justo al oeste tienes la salida a las escaleras, y al este el pasillo se prolonga varios metros. Al norte y al sur hay puertas para entrar en dos de las habitaciones de los maestros guerreros.\n");
	AddExit("norte", "c216");
	AddDoor("norte");
	AddExit("este", "c220");
	AddExit("sur", "c218");
	AddDoor("sur");
	AddExit("oeste", "c214");
}
