/****************************************************************************
Fichero: r_manopla.c
Autor: Riberales
Fecha: 15/03/2006
Descripci�n: Habitaci�n de entrene en manoplas.
[t]: 28/02/2009 A�ado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"manopla","manoplas"});

    SetIntShort("la sala de manoplas");

    SetIntLong("Te encuentras en una de las salas de adiestramiento, dedicada"
               " al entrenamiento en manoplas. Observas infinidad de este "
               "tipo de armas colgadas por las paredes y estanter�as de la "
               "habitaci�n.\n");

    AddParedes();
    AddVentanaN();

    AddDetail(({"manopla","manoplas","arma","armas"}),
                 "Se trata de guantes recubiertos de filamentos de hierro, lo "
                 "que hace que un individuo experto en la lucha cuerpo a "
                 "cuerpo pueda aumentar su da�o con esta arma.\n");

    AddExit("sur",HAB_PRIMERA_ANNUFAM("pasillo08"));
	AddDoor("sur");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
