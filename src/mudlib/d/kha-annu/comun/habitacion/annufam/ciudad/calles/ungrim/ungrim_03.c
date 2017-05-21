/****************************************************************************
Fichero: ungrim_03.c
Autor: Kastwey
	   [T] Tagoras
Creación: 22/08/2005
Descripción: Continuación de la calle Ungrim
[T] 09/03/2009: Añado puerta y todo lo que conlleva
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
	::create();
	SetIntShort("la calle Ungrim");
	SetIntLong("Caminas a lo largo de la calle Ungrim. En este punto "
				"puedes observar una tienda al norte, y sobre ella una de "
				"las habitaciones de la posada. al sur, por el contrario, "
				"se encuentra la conocida taberna Ojo de Orco. La calle "
				"sigue de este a oeste.\n");
	AddSuelo();
	AddLuzAntorchas();

	AddDetail(({"habitacion","habitación","habitacion de la posada","arriba"}),
				"Es una de las habitaciones de la posada de la ciudad. Desde "
				"aquí sólo ves la ventana y no alcanzas a observar lo que "
				"hay en el interior.\n");

	AddDetail(({"norte","tienda","pared norte","tienda de ropa"}),
			  "Se trata de la entrada a la tienda de ropa de la ciudad.\n");

	AddDetail(({"sur","pared sur","taberna","taberna ojo de orco"}),
			  "Es la entrada a la taberna Ojo de Orco.\n");

	AddExit("este",HAB_UNGRIM_ANNUFAM("ungrim_04"));
	AddExit("oeste",HAB_UNGRIM_ANNUFAM("ungrim_02"));
	AddExit("norte",HAB_TIENDAS_ANNUFAM("tienda_ropa"));
	AddExit("sur",HAB_TABERNAS_ANNUFAM("ojo_orco.c"));

	AddDoor("norte", "la puerta de la tienda de ropa",
		"Es la puerta que da entrada a la tienda de ropa.\n",
		({"puerta", "puerta de la tienda de ropa"}),
		([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));
}
