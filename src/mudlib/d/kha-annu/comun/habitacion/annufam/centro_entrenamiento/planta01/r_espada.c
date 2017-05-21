/****************************************************************************
Fichero: r_espada.c
Autor: Riberales
Fecha: 05/03/2006
Descripción: Habitación de espada.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"espada","espadas","sable","sables"});

    SetIntShort("la sala de lucha con espada");
    SetIntLong("Te encuentras en lo que parece la sala de práctica de lucha "
               "con espada del centro. Lo supones porque las paredes están "
               "llenas de soportes y estanterías con grandes espadas "
               "colgadas, y vaya, ¿qué otra cosa podría significar eso?\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"arma","armas","espada","sable","espadas","sables"}),
                "Los filos de las espadas y sables destellean cuando les da "
                "la luz. Hay de muchos tipos y tamaños pero todas tienen las "
                "señales inconfundibles de la lucha.\n");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo04"));
	AddDoor("norte");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
