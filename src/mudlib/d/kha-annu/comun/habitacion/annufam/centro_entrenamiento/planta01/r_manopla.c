/****************************************************************************
Fichero: r_manopla.c
Autor: Riberales
Fecha: 15/03/2006
Descripción: Habitación de entrene en manoplas.
[t]: 28/02/2009 Añado puertas
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
               "tipo de armas colgadas por las paredes y estanterías de la "
               "habitación.\n");

    AddParedes();
    AddVentanaN();

    AddDetail(({"manopla","manoplas","arma","armas"}),
                 "Se trata de guantes recubiertos de filamentos de hierro, lo "
                 "que hace que un individuo experto en la lucha cuerpo a "
                 "cuerpo pueda aumentar su daño con esta arma.\n");

    AddExit("sur",HAB_PRIMERA_ANNUFAM("pasillo08"));
	AddDoor("sur");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
