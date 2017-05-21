/* vi: set tabstop=4 */
/** @file c105.c
	@brief un pasillo
	@author SimBuilder
	@version 1.00
	@date 2009-02-27

Este es uno de los pasillos del centro de adiestramiento de guerreros enanos de Anufam y no se observa cambio alguno en el entorno: las mismas paredes, los mismos suelos, las mismas antorchas y las mismas puertas al norte y al sur para entrar a las habitaciones es lo único que hay alrededor. Hacia el este y el oeste el pasillo se prolonga varios metros.
*/

#include "./path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_pasillo");

create() {
	::create();
	SetIntShort("un pasillo");
	SetIntLong("Este es uno de los pasillos del centro de adiestramiento de guerreros enanos de Anufam y no se observa cambio alguno en el entorno: las mismas paredes, los mismos suelos, las mismas antorchas y las mismas puertas al norte y al sur para entrar a las habitaciones es lo único que hay alrededor. Hacia el este y el oeste el pasillo se prolonga varios metros.\n");
	AddExit("norte", "c104");
	AddDoor("norte");
	AddExit("este", "c108");
	AddExit("sur", "c106");
	AddDoor("sur");
	AddExit("oeste", "c102");
}
