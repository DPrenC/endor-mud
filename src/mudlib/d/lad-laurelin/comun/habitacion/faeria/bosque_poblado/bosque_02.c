/***
Fichero: bosque_02.c
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
    "Hacia el oeste, la vegetaci�n es tan espesa que te es imposible pasar.\n");
    SetOficina(HAB_BOSQUE_PUESTO("bosque_01"));
    AddExit("sudeste","bosque_01");
    AddExit("este","bosque_03");
    AddExit("norte","bosque_05");
    AddExit("nordeste","bosque_06");
}
