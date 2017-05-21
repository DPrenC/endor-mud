/****************************************************************************
Fichero: r_escudo.c
Autor: Riberales
Fecha: 17/03/2006
Descripci�n: Habitaci�n de entrene en escudos.
[t]: 28/02/2009 A�ado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"escudo","escudos"});

    SetIntShort("la sala de entrenamiento en parada con escudo");
    SetIntLong("Est�s en la habitaci�n del Centro de Annufam reservada para "
    "el aprendizaje y entrenamiento en la parada con el escudo. Por doquier "
    "observas multitud de escudos de diversos tama�os y formas, pero todos "
    "con algo en com�n, la ense�a del pueblo enano de Kha-annu en su "
    "centro.\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"escudo","escudos","arma","armas"}),
                 "Colgados de las paredes de esta sala hay montones de "
                 "escudos de todas las formas y tama�os. Algunos son redondos,"
                 " algunos cuadrados, algunos grandes, algunos peque�os...\n");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo09"));
	AddDoor("norte");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
