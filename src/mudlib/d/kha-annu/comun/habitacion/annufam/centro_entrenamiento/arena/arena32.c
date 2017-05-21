/* vi: set tabstop=4 */
/** @file arena32.c
	@brief la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

El entrenamiento en Annufam se divide en dos partes: en el interior del edificio, los guerreros enanos aprenden los rudimentos b�sicos del arte de la guerra, y en la Arena, ponen en pr�ctica esas habilidades en simulaciones de ataque y en combates cuerpo a cuerpo. De hecho, puedes ver alg�n enano herido por sus propios compa�eros llevado r�pidamente al interior del edificio que tienes al sur. Hacia el noreste hay una peque�a loma.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena.c");

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("la Arena");
	SetIntLong("El entrenamiento en Annufam se divide en dos partes: en el interior del edificio, los guerreros enanos aprenden los rudimentos b�sicos del arte de la guerra, y en la Arena, ponen en pr�ctica esas habilidades en simulaciones de ataque y en combates cuerpo a cuerpo. De hecho, puedes ver alg�n enano herido por sus propios compa�eros llevado r�pidamente al interior del edificio que tienes al sur. Hacia el noreste hay una peque�a loma.\n");
	AddExit("norte", "arena33");
	AddExit("nordeste", "arena43");
	AddExit("este", "arena42");
	AddExit("sudeste", "arena41");
	AddExit("sur", "arena31");
	AddExit("suroeste", "arena21");
	AddExit("oeste", "arena22");
	AddLoma();
	AddParedLejos();
}
