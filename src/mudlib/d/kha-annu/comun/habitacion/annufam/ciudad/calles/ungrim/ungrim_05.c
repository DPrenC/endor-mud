/****************************************************************************
Fichero: ungrim_05.c
Autor: Riberales
		[T] Tagoras
Creación: 27/09/2005
Descripción: Un tramo de la calle Ungrim.
[T] 10/03/2009: Añadida puerta.
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
    SetIntLong("Caminas por la calle Ungrim, uno de los héroes enanos de "
               "todos los tiempos. Al sur observas la tienda de útiles de "
               "Alibrilla. Al este llegas a un cruce con la Avenida Real, "
               "y al oeste sigue la calle Ungrim. Un par de antorchas "
               "dan luz a esta parte de la calle cuando es necesario.\n");
    AddAntorchas();
    AddSuelo();

    AddDetail(({"pared sur","tienda","sur"}),
              "Se trata de una tienda donde parece que hay cualquier cosa "
              "que pueda venir bien para una emergencia.\n");

    AddExit("oeste",HAB_UNGRIM_ANNUFAM("ungrim_06"));
    AddExit("este",HAB_AVENIDA_ANNUFAM("avenida_03"));
    AddExit("sur",HAB_TIENDAS_ANNUFAM("tienda_varios"));
	AddDoor("sur", "la puerta de la tienda de Alibrilla",
		"Es la puerta que da entrada a la tienda de Alibrilla.\n",
		({"puerta", "puerta de la tienda de Alibrilla"}),
		([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));
}
