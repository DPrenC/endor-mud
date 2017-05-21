/****************************************************************************
Fichero: pasillo02.c
Autor: Riberales
Fecha: 04/03/2006
Descripción: Pasillo en la primera planta del centro de entrenamiento.
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{

    ::create();

    SetIntShort("un pasillo del Centro");
    SetIntLong("Te encuentras uno de los sobrios pasillos del Centro de "
               "Entrenamiento de Annufam. El pasillo se prolonga de este a "
               "oeste y hacia el norte puedes ver una habitación que te llama "
               "la atención porque es diferente a las que te has encontrado "
               "hasta el momento.");


    AddExit("norte",HAB_PRIMERA_ANNUFAM("r_almacen"));
    AddExit("este",HAB_PRIMERA_ANNUFAM("pasillo03"));
    AddExit("oeste",HAB_PRIMERA_ANNUFAM("pasillo01"));

    AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);

}

