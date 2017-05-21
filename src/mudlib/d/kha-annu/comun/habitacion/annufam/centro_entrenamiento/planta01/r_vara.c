/****************************************************************************
Fichero: r_vara.c
Autor: Riberales
Fecha: 17/03/2006
Descripci�n: Habitaci�n de entrene en varas.
[t]: 28/02/2009 A�ado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"vara","varas"});

    SetIntShort("la sala de lucha con varas");
    SetIntLong("Te encuentras en la sala de lucha con varas del Centro de "
               "Adiestramiento de Guerreros Enanos de Annufam. La decoraci�n "
               "de la sala se reduce a unas antorchas, a un mont�n de "
               "estanter�as y soportes con varas de muchos tama�os y "
               "materiales, y a una gran ense�a del dominio de Kha-annu en "
               "una de las paredes.\n");

    AddParedes();
    AddVentanaN();

    AddDetail(({"vara","varas","arma","armas"}),
                 "Observas una gran cantidad de varas colgadas de la pared, "
                 "de muchos tipos y materiales, seg�n el tipo de entrenamiento"
                 " que se desee realizar.\n");

    AddExit("sur", HAB_PRIMERA_ANNUFAM("pasillo10"));
	AddDoor("sur");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
