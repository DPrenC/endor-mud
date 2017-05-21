/****************************************************************************
Fichero: hab_sur.c
Autor: Kastwey
		[T] Tagoras
Creación: 19/08/2005
Descripción: habitación sur de la posada de Annufam
[T] 22/03/2009: Pongo una puerta estándar
****************************************************************************/

#include "./path.h"
#include <door.h>

inherit HAB_POSADA_ANNUFAM("hab_base_posada");

public void create()
{
	::create();
	SetIntShort("la habitación sur en la posada de Annufam");
	SetIntLong(W("Has entrado a una de las tres habitaciones de esta posada. "
				 "Las tres tienen las mismas sencillas prestaciones: una "
				 "cama, un armario, una mesita de noche y una ventana, que "
				 "en este caso, da al sur.\n"));

//	SetHab("sur");
	AddDetail(({"ventana","ventana sur","sur"}),
			  "A través de esta ventana consigues observar la calle Ungrim, y frente a ti, la Taberna Ojo de Orco.\n");

//	AddExit("norte",#'SalirPasillo);
	AddExit("norte", HAB_POSADA_ANNUFAM("pasillo_piso1"));
	AddDoor("norte", "una puerta", "Es una puerta normal y corriente.\n", "", ([P_DOOR_LOCK_STATE: DOOR_LOCKED]));
}
