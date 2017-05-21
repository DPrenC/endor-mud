/****************************************************************************
Fichero: hab_oeste.c
Autor: Kastwey
		[T] Tagoras
Creaci�n: 19/08/2005
Descripci�n: habitaci�n este de la posada de Annufam
[T] 22/03/2009: Pongo una puerta est�ndar.
****************************************************************************/

#include "./path.h"
#include <door.h>

inherit HAB_POSADA_ANNUFAM("hab_base_posada");

public void create()
{
	::create();
	SetIntShort("la habitaci�n oeste en la posada de Annufam");
	SetIntLong(W("Esta es una de las tres habitaciones de la posada. Como "
				 "casi todo en esta ciudad, no tiene ning�n aderezo. Consta "
				 "de una humilde cama, una mesita de noche y un armario. "
				 "Tambi�n puedes ver una ventana en la pared norte.\n"));

//	SetHab("oeste"); // la direcci�n de la habitaci�n
	AddDetail(({"norte","ventana","ventana norte"}),
			  "A trav�s de la ventana ves la calle Thualin, y al frente el Centro de Adiestramiento.\n");

//	AddExit("este",#'SalirPasillo);
	AddExit("este", HAB_POSADA_ANNUFAM("pasillo_piso1"));
	AddDoor("este", "una puerta", "Es una puerta normal y corriente.\n", "", ([P_DOOR_LOCK_STATE: DOOR_LOCKED]));
}
