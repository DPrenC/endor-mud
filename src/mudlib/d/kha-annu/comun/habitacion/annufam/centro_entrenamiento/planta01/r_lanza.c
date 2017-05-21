/****************************************************************************
Fichero: r_lanza.c
Autor: Tagoras
Fecha: 27/02/2009
Descripci�n: Habitaci�n de entrene en lanza.
[t]: 28/02/2009 A�ado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"lanza","lanzas"});

    SetIntShort("la habitaci�n de lucha con lanza");

    SetIntLong("Esta es la sala donde los reclutas enanos de Annufam practican la lucha con lanza. Tampoco es un arma muy utilizada en Simauria pero ya te ha quedado muy claro que aqu� no est�n dispuestos a dejarse sorprender por nadie, venga �ste armado con lo que venga. No observas demasiados cambios respecto al resto de habitaciones que has visto.\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"lanza","lanzas","arma","armas"}),
                 "Est�n colgadas de cientos de soportes por toda la sala y te preguntas si habr� enanos suficientes para agarrar todas esas lanzas.");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo07"));
	AddDoor("norte");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
