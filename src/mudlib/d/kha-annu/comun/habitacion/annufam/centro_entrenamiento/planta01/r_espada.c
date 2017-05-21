/****************************************************************************
Fichero: r_espada.c
Autor: Riberales
Fecha: 05/03/2006
Descripci�n: Habitaci�n de espada.
[t]: 28/02/2009 A�ado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"espada","espadas","sable","sables"});

    SetIntShort("la sala de lucha con espada");
    SetIntLong("Te encuentras en lo que parece la sala de pr�ctica de lucha "
               "con espada del centro. Lo supones porque las paredes est�n "
               "llenas de soportes y estanter�as con grandes espadas "
               "colgadas, y vaya, �qu� otra cosa podr�a significar eso?\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"arma","armas","espada","sable","espadas","sables"}),
                "Los filos de las espadas y sables destellean cuando les da "
                "la luz. Hay de muchos tipos y tama�os pero todas tienen las "
                "se�ales inconfundibles de la lucha.\n");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo04"));
	AddDoor("norte");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
