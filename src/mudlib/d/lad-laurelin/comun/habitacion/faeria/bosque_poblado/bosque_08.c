/***
Fichero: bosque_08.c
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
    "Hacia el oeste, la vegetación es tan espesa que te es imposible pasar.\n");
    SetOficina(HAB_BOSQUE_PUESTO("bosque_06"));
    AddExit("sudeste","bosque_06");
    AddExit("este","bosque_09");
    AddExit("sur","bosque_05");
    AddExit("nordeste","bosque_11");
}