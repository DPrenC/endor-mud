/***
Fichero: bosque_10.c
Autor: kastwey@simauria
Descripci�n: bosque de siempreunidos.
Creaci�n: 18/12/2004
***/

#include "path.h"

inherit HAB_BOSQUE_PUESTO("bosque_base");

create()
{
    ::create();
    SetIntLong(::QueryIntLong() +
    "La vegetaci�n es tan tupida hacia el este que te es imposible seguir por ah�.\n");
    SetOficina(HAB_BOSQUE_PUESTO("bosque_06"));
    AddExit("oeste","bosque_09");
    AddExit("suroeste","bosque_06");
    AddExit("sur","bosque_07");
    AddExit("noroeste","bosque_11");
}