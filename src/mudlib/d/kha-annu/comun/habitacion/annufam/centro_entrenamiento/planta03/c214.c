/* vi: set tabstop=4 */
/** @file c214.c
	@brief la parte superior de las escaleras
	@author SimBuilder
	@version 1.00
	@date 2009-03-07

Est�s en la parte superior de las escaleras del centro de adiestramiento para reclutas enanos de Annufam y notas que los �nicos elementos decorativos que emplean en este edificio son antorchas y cabezas de le�n. Hacia el este y el oeste se prolonga el pasillo al que se abren las habitaciones de los maestros guerreros, y al norte y al sur est�n las habitaciones de Altriv, el director.
*/

#include "./path.h"

inherit HAB_CENTRO_ANNUFAM("base_centro.c");

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("la parte superior de las escaleras");
	SetIntLong("Est�s en la parte superior de las escaleras del centro de adiestramiento para reclutas enanos de Annufam y notas que los �nicos elementos decorativos que emplean en este edificio son antorchas y cabezas de le�n. Hacia el este y el oeste se prolonga el pasillo al que se abren las habitaciones de los maestros guerreros, y al norte y al sur est�n las habitaciones de Altriv, el director.\n");
	AddDetail(({"escalera", "escaleras"}), "Son unas escaleras de piedra con una cabeza de le�n al principio de la barandilla como �nico ornamento. Si bajas por ellas ir�s a la planta destinada a los soldados y reclutas de Annufam.\n");
	AddExit("norte", "c213");
	AddExit("este", "c217");
	AddExit("sur", "c215");
	AddExit("oeste", "c211");
	AddExit("abajo", HAB_SEGUNDA_ANNUFAM("c114"));
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
}
