/****************************************************************************
Fichero: arena20.c
Autor: Kastwey
Fecha: 19/02/2006
Descripci�n: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Aqu�, la tierra desciende en pendiente, hasta adentrarse en las "
               "aguas del lago. Puedes seguir bordeando la costa si vas al "
               "oeste, ya que al este la vegetaci�n es tan espesa que te "
               "ser�a imposible pasar.\n");


    AnadeDetalleLago("norte");

    AddExit("oeste","arena19");
    AddExit("sur","arena18");
    AddExit("sudeste","arena15");
    AddExit("suroeste","arena17");

}


