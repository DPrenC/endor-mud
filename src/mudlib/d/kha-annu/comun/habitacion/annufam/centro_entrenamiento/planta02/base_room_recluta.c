/****************************************************************************
Fichero: base_room_soldado
Autor: Tagoras
Fecha: 27/02/2009
Descripción: Base de las rooms de los soldado de la primera planta
****************************************************************************/

#include "path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_room");

create()
{
    ::create();
	SetIntShort("la habitación de un recluta");
	SetIntLong("En este piso ya compruebas algún detalle que hace pensar que aquí viven seres vivos. En las habitaciones de lucha no has visto ningún ornamento pero aquí ya empiezas a ver alguna pintura colgada en la pared, algunas monedas sobre una pequeña mesa, y por supuesto la cama reglamentaria con su mesita y su armario a juego.\n");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT, 1);
}
