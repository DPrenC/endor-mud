/****************************************************************************
Fichero: r_maza.c
Autor: Riberales
Fecha: 17/03/2006
Descripción: Habitación de entrene en manoplas.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"maza","mazas"});

    SetIntShort("la sala de lucha con maza");

    SetIntLong("Te encuentras en la sala dedicada al adiestramiento en las "
               "mazas. Por doquier ves multitud de estas armas, de todos los "
               "tamaños, y de diversos tipos: De madera, de hierro, con "
               "pinchos, sin pinchos.... Una verdadera armería de mazas.\n");

    AddParedes();
    AddVentanaN();

    AddDetail(({"maza","mazas","arma","armas"}),
                 "Ves lo que es habitual en este Centro, muchas armas "
                 "colgadas de las paredes, en esta ocasión mazas muy grandes "
                 "y muy pesadas capaces de clavar cualquier clavo, y por "
                 "supuesto, de hundir a un enemigo dos palmos bajo tierra.");

    AddExit("sur", HAB_PRIMERA_ANNUFAM("pasillo09"));
	AddDoor("sur");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
