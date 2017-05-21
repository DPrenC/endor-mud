/* vi: set tabstop=4 */
/** @file c202.c
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
	SetIntShort("el extremo oeste del pasillo");
	SetIntLong("Estás en el extremo oeste del pasillo del último piso del centro de adiestramiento de guerreros enanos de Annufam y la verdad es que no ha cambiado mucho del resto. Las paredes siguen estando igual de desnudas a excepción de unas cuantas antorchas y poco más. Hacia el este recorres el pasillo camino de las escaleras, y al norte y al sur tienes la entrada a dos habitaciones.\n");
	AddExit("norte", "c201");
	AddDoor("norte");
	AddExit("este", "c205");
	AddExit("sur", "c203");
	AddDoor("sur");
}
