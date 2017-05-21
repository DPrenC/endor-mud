/****************************************************************************
Fichero: pasillo01.c
Autor: Riberales
Fecha: 04/03/2006
Descripción: Pasillo en la primera planta del centro de entrenamiento.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{

    ::create();

    SetIntShort("un pasillo");
    SetIntLong("Estás en uno de los extremos del pasillo de la planta baja "
               "del Centro de Entrenamiento de Guerreros Enanos de Annufam. "
               "Sigue predominando el verde y el marrón en el ambiente, y "
               "todo sigue siendo igual de espartano. Al norte y al sur "
               "puedes ver las puertas que conducen a las salas de "
               "entrenamiento.\n");


    AddExit("norte",HAB_PRIMERA_ANNUFAM("r_alabarda"));
	AddDoor("norte");
    AddExit("sur",HAB_PRIMERA_ANNUFAM("r_hacha01"));
	AddDoor("sur");
    AddExit("este",HAB_PRIMERA_ANNUFAM("pasillo02"));

    AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);

}

