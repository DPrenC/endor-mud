/****************************************************************************
Fichero: r_daga.c
Autor: Riberales
Fecha: 05/03/2006
Descripción: Habitación de dagas.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"daga","dagas"});

    SetIntShort("la sala de daga");
    SetIntLong("Acabas de entrar en lo que es la sala de entrenamiento de "
               "lucha con daga del centro de entrenamiento de reclutas enanos "
               "de Annufam. Aquí el decorado no cambia mucho del del resto de "
               "la planta pero hay algo que te llama la atención: la cantidad "
               "de dagas diferentes que pueden llegarse a reunir en una sola "
               "sala. Todas las paredes están llenas de estanterías y "
               "soportes en las que sólo ves dagas y más dagas de todos los "
               "tipos y tamaños.\n");

    AddParedes();
    AddVentanaN();

    AddDetail(({"arma","armas","daga","dagas"}),
                "Son armas de filo pequeñas pero muy peligrosas. En las manos "
                "adecuadas, estas dagas y cuchillos pueden rebanar un gaznate "
                "en menos que canta un gallo.\n");

    AddExit("sur",HAB_PRIMERA_ANNUFAM("pasillo04"));
	AddDoor("sur");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
