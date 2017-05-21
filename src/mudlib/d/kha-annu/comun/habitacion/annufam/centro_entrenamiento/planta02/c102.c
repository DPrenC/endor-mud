/* vi: set tabstop=4 */
/** @file c102.c
	@brief el extremo oeste de un pasillo
	@author SimBuilder
	@version 1.00
	@date 2009-02-27

Este es el extremo oeste del pasillo del primer piso del centro de adiestramiento de guerreros enanos de Annufam y la verdad es que no ha cambiado mucho desde sus inicios. Las paredes siguen estando igual de desnudas a excepción de unas cuantas antorchas y poco más. Hacia el este se recorre el pasillo, y al norte y al sur hay las puertas de dos habitaciones.
*/

#include "./path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_pasillo");

create() {
	::create();
	SetIntShort("el extremo oeste de un pasillo");
	SetIntLong("Este es el extremo oeste del pasillo del primer piso del centro de adiestramiento de guerreros enanos de Annufam y la verdad es que no ha cambiado mucho desde sus inicios. Las paredes siguen estando igual de desnudas a excepción de unas cuantas antorchas y poco más. Hacia el este se recorre el pasillo, y al norte y al sur hay las puertas de dos habitaciones.\n");
	AddExit("norte", "c101");
	AddDoor("norte");
	AddExit("este", "c105");
	AddExit("sur", "c103");
	AddDoor("sur");
}
