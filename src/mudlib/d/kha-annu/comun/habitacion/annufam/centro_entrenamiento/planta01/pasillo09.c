/****************************************************************************
Fichero: pasillo09.c
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

    SetIntShort("un pasillo del Centro");
    SetIntLong("Te encuentras en mitad de un pasillo que discurre de este a "
               "oeste. Todo su aderezo consiste en algunos faroles y el "
               "predominio del verde y el marrón, colores de la enseña de "
               "Kha-annu. Al norte y al sur hay dos puertas que llevan a "
               "diferentes habitaciones de entrenamiento.\n");



    AddExit("norte",HAB_PRIMERA_ANNUFAM("r_maza"));
	AddDoor("norte");
    AddExit("sur",HAB_PRIMERA_ANNUFAM("r_escudo"));
	AddDoor("sur");
    AddExit("este",HAB_PRIMERA_ANNUFAM("pasillo10"));
    AddExit("oeste",HAB_PRIMERA_ANNUFAM("pasillo08"));
    AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);

}
