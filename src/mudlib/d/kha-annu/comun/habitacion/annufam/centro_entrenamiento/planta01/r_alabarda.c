/****************************************************************************
Fichero: r_alabarda
Autor: Riberales
Fecha: 21/02/2006
Descripci�n: Habitaci�n de alabardas
[t]: 28/02/2009 A�ado puertas
****************************************************************************/



#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    tipo_arma = ({"alabarda","alabardas"});
    ::create();

    SetIntShort("la sala de alabarda");
    SetIntLong("A cada paso que das aparece algo nuevo. No es que el centro "
               "sea muy barroco, con decorados cargados, pero vaya... "
               "alabardas. �Alguien usa alabardas para luchar? Se ve que los "
               "enanos no est�n dispuestos a dejarse sorprender por nadie, "
               "venga �ste armado con lo que venga.\n");

    AddVentanaN();
    AddParedes();

    AddDetail(({"arma","armas","alabarda","alabardas"}),
                "Como la mayor�a de armas de Annufam, las alabardas tambi�n "
                "est�n forjadas en acero. Son unas astas largas que en la "
                "parte superior tienen el filo de un hacha y que rematan en "
                "una punta de lanza.\n");

    AddExit("sur",HAB_PRIMERA_ANNUFAM("pasillo01"));
	AddDoor("sur");

	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
