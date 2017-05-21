/* vi: set tabstop=4 */
/** @file c103.c
	@brief la habitación de un recluta
	@author SimBuilder
	@version 1.00
	@date 2009-02-27

En este piso ya compruebas algún detalle que hace pensar que aquí viven seres vivos. En las habitaciones de lucha no has visto ningún ornamento pero aquí ya empiezas a ver alguna pintura colgada en la pared, algunas monedas sobre una pequeña mesa, y por supuesto la cama reglamentaria con su mesita y su armario a juego.
*/

#include "./path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_room_recluta");

create() {
	::create();
	AddExit("norte", "c102");
	AddDoor("norte");
	AddSWindow();
}
