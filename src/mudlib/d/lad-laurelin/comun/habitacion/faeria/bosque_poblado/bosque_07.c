/***
Fichero: bosque_07.c
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
    SetOficina(HAB_BOSQUE_PUESTO("bosque_03"));
    AddExit("oeste","bosque_06");
    AddExit("suroeste","bosque_03");
    AddExit("norte","bosque_10");
    AddExit("noroeste","bosque_09");
    AddExit("sur","bosque_04");
}