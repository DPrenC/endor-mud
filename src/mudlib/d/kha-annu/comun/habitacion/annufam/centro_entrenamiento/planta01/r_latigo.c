/****************************************************************************
Fichero: r_latigo.c
Autor: Riberales
Fecha: 17/03/2006
Descripción: Habitación de entrene en látigos.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"latigo","latigos","látigos","látigos"});

    SetIntShort("la habitación de lucha con látigo");

    SetIntLong("Te encuentras en la sala reservada para el entrenamiento en "
               "látigo. Las paredes de la habitación están repletas de estas "
               "armas, dándole al lugar un toque sádico debido a la gran "
               "cantidad de cuero.\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"látigo","látigos","latigos","latigos","arma","armas"}),
                 "En las estanterías y soportes hay montones y montones de "
                 "látigos colgados de diferentes tamaños y materiales.");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo08"));
	AddDoor("norte");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
