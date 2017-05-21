/* vi: set tabstop=4 */
/** @file c114.c
	@brief las escaleras
	@author SimBuilder
	@version 1.00
	@date 2009-02-27

Estas son las escaleras del primer piso del centro de adiestramiento para guerreros enanos de Annufam. Aquí es donde los soldados y reclutas tienen sus habitaciones y alguna sala común. Un pasillo se prolonga de este a oeste mientras que al norte y al sur observas dos grandes salas abiertas. Hacia abajo se encuentra la salida del edificio, mientras que hacia arriba se llega a la planta destinada al reposo de los maestros guerreros y el director del centro militar.
*/

#include "./path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_pasillo");

create() {
	::create();
	SetIntShort("las escaleras");
	SetIntLong("Estas son las escaleras del primer piso del centro de adiestramiento para guerreros enanos de Annufam. Aquí es donde los soldados y reclutas tienen sus habitaciones y alguna sala común. Un pasillo se prolonga de este a oeste mientras que al norte y al sur observas dos grandes salas abiertas. Hacia abajo se encuentra la salida del edificio, mientras que hacia arriba se llega a la planta destinada al reposo de los maestros guerreros y el director del centro militar.\n");
	AddDetail(({"escalera", "escaleras"}), "Son unas escaleras de piedra sin más ornamentación que una cabeza de león al principio de la barandilla. Si subes llegarás al piso donde reposan los guerreros y el director del centro y si bajas encontrarás muy fácil la salida.\n");
	AddExit("norte", "c113");
	AddExit("este", "c117");
	AddExit("sur", "c115");
	AddExit("oeste", "c111");
	AddExit("abajo", HAB_PRIMERA_ANNUFAM("pasillo05"));
	AddExit("arriba", HAB_TERCERA_ANNUFAM("c214"));
}
