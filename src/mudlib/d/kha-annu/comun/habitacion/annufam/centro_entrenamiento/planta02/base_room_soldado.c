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
	SetIntShort("la habitaci�n de un soldado");
	SetIntLong("Parece que estos enanos guerreros no son tan sobrios como aparentan en un principio. En esta habitaci�n observas el mobiliario habitual y tambi�n un par de pinturas en las paredes que a diferencia de las que has visto en el centro no son de guerra y destrucci�n. Desde la ventana tambi�n se puede ver el exterior del edificio.\n");
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
}
