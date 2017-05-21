/****************************************************************************
Fichero: r_latigo.c
Autor: Riberales
Fecha: 17/03/2006
Descripci�n: Habitaci�n de entrene en l�tigos.
[t]: 28/02/2009 A�ado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"latigo","latigos","l�tigos","l�tigos"});

    SetIntShort("la habitaci�n de lucha con l�tigo");

    SetIntLong("Te encuentras en la sala reservada para el entrenamiento en "
               "l�tigo. Las paredes de la habitaci�n est�n repletas de estas "
               "armas, d�ndole al lugar un toque s�dico debido a la gran "
               "cantidad de cuero.\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"l�tigo","l�tigos","latigos","latigos","arma","armas"}),
                 "En las estanter�as y soportes hay montones y montones de "
                 "l�tigos colgados de diferentes tama�os y materiales.");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo08"));
	AddDoor("norte");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
