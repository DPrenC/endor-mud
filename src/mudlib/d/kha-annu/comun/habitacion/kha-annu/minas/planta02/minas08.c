/**************************************************************************
fichero: minas07.c
Autor: Riberales
Creación: 9/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("una pequeña bifurcación");
    SetIntLong("Has llegado a un pequeño cruce de caminos, y si no fuera por "
               "lo irregular de las minas, dirías que son idénticos. Al final "
               "del túnel del norte te parece divisar un poco de luz, mientras"
               " que los que van al suroeste y sudeste siguen con la misma "
               "penumbra que casi toda la zona.\n");

    DetalleParedes();
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);

    AddExit("norte",HAB_SEGUNDA_MINAS("minas03"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas07"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas09"));
    AddGuardia();
}
