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
	SetIntShort("la habitación de un soldado");
	SetIntLong("Parece que estos enanos guerreros no son tan sobrios como aparentan en un principio. En esta habitación observas el mobiliario habitual y también un par de pinturas en las paredes que a diferencia de las que has visto en el centro no son de guerra y destrucción. Desde la ventana también se puede ver el exterior del edificio.\n");
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
}
