/* vi: set tabstop=4 */
/** @file arena51.c
	@brief la entrada a la Arena
	@author Tagoras
	@version 1.00
	@date 2009-03-08

Aqu� se abre una gran extensi�n en la que el olor agrio del sudor impregna el ambiente. Te das cuenta de que est�s en la famosa Arena de Annufam, y la verdad es que tiene un aspecto mucho m�s siniestro del que cuenta la leyenda: charcos de sangre aqu� y all�, gritos de guerra, decenas de armas de todos los tipos y tama�os apiladas y centenares de enanos en actitud de combate es el desolador y amurallado paisaje que se pinta ante tus ojos. Al sur tienes la entrada al edificio, y en el resto de direcciones, la Arena se extiende implacable.
*/

#include "./path.h"

inherit HAB_ARENA_ANNUFAM("base_arena_trasera.c");

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("la entrada a la Arena");
	SetIntLong("Aqu� se abre una gran extensi�n en la que el olor agrio del sudor impregna el ambiente. Te das cuenta de que est�s en la famosa Arena de Annufam, y la verdad es que tiene un aspecto mucho m�s siniestro del que cuenta la leyenda: charcos de sangre aqu� y all�, gritos de guerra, decenas de armas de todos los tipos y tama�os apiladas y centenares de enanos en actitud de combate es el desolador y amurallado paisaje que se pinta ante tus ojos. Al sur tienes la entrada al edificio, y en el resto de direcciones, la Arena se extiende implacable.\n");
	AddExit("norte", "arena52");
	AddExit("nordeste", "arena62");
	AddExit("este", "arena61");
	AddExit("sur", HAB_PRIMERA_ANNUFAM("pasillo06"));
	AddExit("oeste", "arena41");
	AddExit("noroeste", "arena42");
}
