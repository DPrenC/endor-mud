/****************************************************************************
#include <properties.h>
Fichero: pasillo03.c
Autor: Riberales
Fecha: 05/03/2006
Descripción: Pasillo en la planta baja del centro de annufam
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{
    ::create();
    SetIntShort("un pasillo del Centro");
    SetIntLong("El pasillo presenta un aspecto espartano, muy en consonancia "
               "con el edificio. A fin de cuentas estás en el Centro de "
               "Adiestramiento para Guerreros Enanos. Al norte y al sur "
               "puedes ver las puertas que conducen a las salas donde se "
               "entrena, mientras que el corredor sigue de este a oeste.\n");

    AddExit("este",HAB_PRIMERA_ANNUFAM("pasillo04"));
    AddExit("oeste",HAB_PRIMERA_ANNUFAM("pasillo02"));
    AddExit("norte",HAB_PRIMERA_ANNUFAM("r_cadena"));
	AddDoor("norte");
    AddExit("sur",HAB_PRIMERA_ANNUFAM("r_esgrima"));
	AddDoor("sur");
    AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);

}

