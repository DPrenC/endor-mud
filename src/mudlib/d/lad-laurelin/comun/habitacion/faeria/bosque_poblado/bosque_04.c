/***
Fichero: bosque_04.c
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
    SetOficina(HAB_BOSQUE_PUESTO("bosque_01"));
    AddExit("oeste","bosque_03");
    AddExit("suroeste","bosque_01");
    AddExit("norte","bosque_07");
    AddExit("noroeste","bosque_06");
}