/****************************************************************************
Fichero: pasillo08.c
Autor: Riberales
Fecha: 15/03/2006
Descripción: Pasillo del CAGE.
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{
    ::create();

    SetIntShort("un pasillo del Centro");
    SetIntLong("Te encuentras en el pasillo de la planta baja del CENTRO de "
               "Annufam. El mismo va de este a oeste, mientras que al norte "
               "y al sur hay diferentes salas de entrenamiento para los "
               "enanos.\n");




    AddExit("norte",HAB_PRIMERA_ANNUFAM("r_manopla"));
	AddDoor("norte");
    AddExit("sur",HAB_PRIMERA_ANNUFAM("r_latigo"));
	AddDoor("sur");
    AddExit("este",HAB_PRIMERA_ANNUFAM("pasillo09"));
    AddExit("oeste",HAB_PRIMERA_ANNUFAM("pasillo07"));
    AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);

}
