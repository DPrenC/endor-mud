/****************************************************************************
Fichero: arena20.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Aquí, la tierra desciende en pendiente, hasta adentrarse en las "
               "aguas del lago. Puedes seguir bordeando la costa si vas al "
               "oeste, ya que al este la vegetación es tan espesa que te "
               "sería imposible pasar.\n");


    AnadeDetalleLago("norte");

    AddExit("oeste","arena19");
    AddExit("sur","arena18");
    AddExit("sudeste","arena15");
    AddExit("suroeste","arena17");

}


