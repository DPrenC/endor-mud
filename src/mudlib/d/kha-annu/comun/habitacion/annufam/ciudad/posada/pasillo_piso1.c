/****************************************************************************
Fichero: pasillo_piso1.c
Autor: Kastwey
		[Tagoras]
Creación: 19/08/2005
Descripción: descansillo del primer piso de la posada de Annufam
[T] 22/03/2009: Pongo puertas estándar.
****************************************************************************/

#include "./path.h"
#include <door.h>

#define HAB_ESTE		(HAB_POSADA_ANNUFAM("hab_este"))

inherit BASE_CIUDAD_ANNUFAM;

public int door_change_state(object door, string exit, string action, string str)
{
//if (find_object("tagoras")) dtell("tagoras",sprintf("La acción de la puerta %s es %s\n", exit, action));
    if ("abrir"==action)
		HAB_ESTE->notify_open();
    if ("cerrar"==action)
		HAB_ESTE->notify_close();
    return 1;
}

public void create()
{
	::create();
	SetIntShort("un descansillo entre habitaciones");
	SetIntLong(W("Te encuentras en el descansillo del piso superior de la "
				 "posada. Aquí están las escaleras que te conducen a la "
				 "recepción de la misma, y tres puertas dan a parar a tres "
				 "habitaciones de descanso.\n"));
	SetIndoors(1);
	SetIntBright(50);

	AddDetail(({"puerta","puertas"}),
			  W("Las tres puertas son idénticas. No muy gruesas y con un "
				"pomo para abrirlas. A simple vista, la verdad es que no te "
				"parecen muy resistentes. Ante cada puerta, puedes ver una "
				"alfombrilla.\n"));

	AddDetail(({"escalera","escaleras"}),
			  W("Son unas escaleras de toda la vida, en este caso, en "
				"forma de caracol. Comunican los dos pisos de la posada.\n"));

	AddDetail(({"alfombra","alfombrilla","alfombras","alfombrillas"}),
			  W("Son unos burdos trozos de piel curtida de algún animal. "
				"Están colocadas ante las puertas de las habitaciones, para "
				"evitar que se ensucien. Dudas de que en la práctica "
				"sean realmente algo más que adornos.\n"));
	AddExit("abajo",HAB_POSADA_ANNUFAM("entrada_posada"));
	AddExit("este", "hab_este");
	AddDoor("este", "una puerta", "Es una puerta idéntica a las otras dos que puedes ver al sur y al oeste.\n", ({"puerta", "puerta este"}), "llave_maestra_posada_annufam", ([P_DOOR_LOCK_STATE: DOOR_LOCKED,
			P_DOOR_CHANGE_STATE_FUNCTION: #'door_change_state]));
	AddExit("sur", "hab_sur");
	AddDoor("sur", "una puerta", "Es una puerta idéntica a las otras dos que puedes ver al este y al oeste.\n", ({"puerta", "puerta sur"}), "llave_maestra_posada_annufam", ([P_DOOR_LOCK_STATE: DOOR_LOCKED]));
	AddExit("oeste", "hab_oeste");
	AddDoor("oeste", "una puerta", "Es una puerta idéntica a las otras dos que puedes ver al este y al sur.\n", ({"puerta", "puerta oeste"}), "llave_maestra_posada_annufam", ([P_DOOR_LOCK_STATE: DOOR_LOCKED]));
}
