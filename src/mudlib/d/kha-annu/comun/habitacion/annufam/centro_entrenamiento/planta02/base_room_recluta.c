/****************************************************************************
Fichero: base_room_soldado
Autor: Tagoras
Fecha: 27/02/2009
Descripci�n: Base de las rooms de los soldado de la primera planta
****************************************************************************/

#include "path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_room");

create()
{
    ::create();
	SetIntShort("la habitaci�n de un recluta");
	SetIntLong("En este piso ya compruebas alg�n detalle que hace pensar que aqu� viven seres vivos. En las habitaciones de lucha no has visto ning�n ornamento pero aqu� ya empiezas a ver alguna pintura colgada en la pared, algunas monedas sobre una peque�a mesa, y por supuesto la cama reglamentaria con su mesita y su armario a juego.\n");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT, 1);
}
