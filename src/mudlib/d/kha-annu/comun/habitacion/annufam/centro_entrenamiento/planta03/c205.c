/* vi: set tabstop=4 */
/** @file c205.c
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
	SetIntLong("Estás en un pasillo del tercer piso del centro de adiestramiento de guerreros enanos de Annufam y sigues contemplando el mismo aspecto que en el resto del edificio. Parece que estos guerreros enanos se toman muy en serio su entrenamiento. El pasillo avanza de este a oeste y tanto al norte como al sur tienes la entrada a dos habitaciones.\n");
	AddExit("norte", "c204");
	AddDoor("norte");
	AddExit("este", "c208");
	AddExit("sur", "c206");
	AddDoor("sur");
	AddExit("oeste", "c202");
}
