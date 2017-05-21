/****************************************************************************
Fichero: pasillo04
Autor: Riberales
Fecha: 05/03/2006
Descripción: Pasillonen la planta baja de Annufam.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{
    ::create();
    SetIntShort("un pasillo");
    SetIntLong("Estás en un pasillo del Centro de Annufam. Al este se "
               "encuentran las escaleras que dan acceso a los pisos "
               "superiores, y en dirección contraria el pasillo se prolonga "
               "unos cuantos metros más. Al norte y al sur puedes ver sendas "
               "puertas que conducen a las salas de entrenamiento.\n");

    AddExit("este",HAB_PRIMERA_ANNUFAM("pasillo05"));
    AddExit("oeste",HAB_PRIMERA_ANNUFAM("pasillo03"));
    AddExit("norte",HAB_PRIMERA_ANNUFAM("r_daga"));
	AddDoor("norte");
    AddExit("sur",HAB_PRIMERA_ANNUFAM("r_espada"));
	AddDoor("sur");

    AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);


}
