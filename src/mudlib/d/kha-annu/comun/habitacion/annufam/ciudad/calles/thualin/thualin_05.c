/****************************************************************************
Fichero: Thualin_05.c
Autor: Riberales
		[T] Tagoras
Creación: 01/10/2005
Descripción: Un tramo de la calle Thualin.
[T] 11/03/2009: Añadida conexión con las taquillas y puerta
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit HAB_THUALIN_ANNUFAM("thualin_base");

public void create()
{
    ::create();

    SetIntShort("la calle Thualin");
    SetIntLong("Paseas por la calle Thualin, dedicada a uno de los más "
               "famosos guerreros enanos. Esta calle atraviesa la ciudad de "
               "este a oeste y discurre paralela a la pared meridional del "
               "Centro de Adiestramiento. Al sur puedes ver la entrada a la "
               "sucursal de consignas aquí en Annufam, al oeste sigue la "
               "calle, y al este se encuentra la Plaza Belthain, por donde "
               "se entra al Centro.\n");
    AddLuzAntorchas();
    AddSuelo();
    AddDetail("consignas",
            "Es la fachada de la sucural de consignas de Annufam, donde "
            "puedes alquilar cajas y depositar tus objetos más preciados.\n");
    AddExit("este",HAB_CIUDAD_ANNUFAM("plaza"));
    AddExit("oeste",HAB_THUALIN_ANNUFAM("thualin_06"));
    AddExit("sur",HAB_TIENDAS_ANNUFAM("taquillas"));
    AddDoor("sur", "la puerta de las consignas", "Es la puerta para entrar en las consignas.\n",
    ({"puerta", "puerta de las consignas", "puerta del sur"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta2"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta2"),
    P_MATERIAL:M_MADERA, P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));
}
