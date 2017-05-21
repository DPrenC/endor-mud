/****************************************************************************
Fichero: pasillo07.c
Autor: Riberales
Fecha: 12/03/2006
Descripción: Pasillo del CAGE.
[t] 27/02/2009: Añado la salida sur a r_lanza
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{
    ::create();

    SetIntShort("un pasillo");
    SetIntLong("Te encuentras en uno de los pasillos del Centro de "
               "Adiestramiento para Guerreros Enanos de Annufam. El pasillo "
               "se prolonga de este a oeste, y al norte y al sur hay puertas que dan "
               "a salas de entrenamiento.");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("r_mangual"));
	AddDoor("norte");
    AddExit("sur",HAB_PRIMERA_ANNUFAM("r_lanza"));
	AddDoor("sur");
    AddExit("este",HAB_PRIMERA_ANNUFAM("pasillo08"));
    AddExit("oeste",HAB_PRIMERA_ANNUFAM("pasillo05"));
    AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);

}
