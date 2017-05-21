/****************************************************************************
Fichero: r_escudo.c
Autor: Riberales
Fecha: 17/03/2006
Descripción: Habitación de entrene en escudos.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"escudo","escudos"});

    SetIntShort("la sala de entrenamiento en parada con escudo");
    SetIntLong("Estás en la habitación del Centro de Annufam reservada para "
    "el aprendizaje y entrenamiento en la parada con el escudo. Por doquier "
    "observas multitud de escudos de diversos tamaños y formas, pero todos "
    "con algo en común, la enseña del pueblo enano de Kha-annu en su "
    "centro.\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"escudo","escudos","arma","armas"}),
                 "Colgados de las paredes de esta sala hay montones de "
                 "escudos de todas las formas y tamaños. Algunos son redondos,"
                 " algunos cuadrados, algunos grandes, algunos pequeños...\n");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo09"));
	AddDoor("norte");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
