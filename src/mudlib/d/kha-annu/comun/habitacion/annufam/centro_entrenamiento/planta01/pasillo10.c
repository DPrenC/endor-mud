/****************************************************************************
Fichero: pasillo10.c
Autor: Riberales
Fecha: 17/03/2006
Descripción: Pasillo del CAGE.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{
    ::create();

    SetIntShort("el extremo de un pasillo del Centro");
    SetIntLong("Te encuentras en el extremo oriental de uno de los pasillos "
               "del Centro de Annufam. Al norte y al sur observas dos puertas "
               "que comunican el pasillo con las salas de entrenamiento, "
               "mientras que al oeste el pasillo discurre sobrio y "
               "espartano.\n");





    AddExit("norte",HAB_PRIMERA_ANNUFAM("r_vara"));
	AddDoor("norte");
    AddExit("sur",HAB_PRIMERA_ANNUFAM("r_marciales"));
	AddDoor("sur");
    AddExit("oeste",HAB_PRIMERA_ANNUFAM("pasillo09"));
    AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);

}
