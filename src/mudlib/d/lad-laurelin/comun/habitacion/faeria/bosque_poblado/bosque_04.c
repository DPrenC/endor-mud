/***
Fichero: bosque_04.c
Autor: kastwey@simauria
Descripción: bosque de siempreunidos.
Creación: 18/12/2004
***/

#include "path.h"

inherit HAB_BOSQUE_PUESTO("bosque_base");

create()
{
    ::create();
    SetIntLong(::QueryIntLong() +
    "La vegetación es tan tupida hacia el este que te es imposible seguir por ahí.\n");
    SetOficina(HAB_BOSQUE_PUESTO("bosque_01"));
    AddExit("oeste","bosque_03");
    AddExit("suroeste","bosque_01");
    AddExit("norte","bosque_07");
    AddExit("noroeste","bosque_06");
}