/****************************************************************************
Fichero: r_esgrima.c
Autor: Riberales
Fecha: 05/03/2006
Descripci�n: Sala de esgrima.
[t]: 28/02/2009 A�ado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"florete", "floretes"});

    SetIntShort("la sala de esgrima");
    SetIntLong("Est�s en una de las salas de adiestramiento de Annufam. En "
               "�sta, particularmente, se practica el arte de la esgrima. Como "
               "todas las salas de entrenamiento del centro, esta es muy "
               "sobria y espartana. De las paredes sobresalen unas antorchas "
               "que iluminan la estancia, pero no hay ninguna decoraci�n "
               "excepto una gran ense�a del dominio de Kha-annu y una "
               "infinidad de soportes de los cuales cuelgan varias armas de "
               "filo entre las que destacan unos magn�ficos floretes de "
               "acero.\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"armas","arma","floretes"}),
                "Apoyados en sus soportes, los floretes de las paredes "
                "parecen  mucho menos peligrosos que en manos de un experto "
                "espadach�n.\n");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo03"));
	AddDoor("norte");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
