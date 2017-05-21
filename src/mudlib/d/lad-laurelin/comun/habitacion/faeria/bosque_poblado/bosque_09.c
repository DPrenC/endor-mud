/***
Fichero: bosque_09.c
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
    "Aquí el bosque se extiende en todas direcciones.");
    SetOficina(HAB_BOSQUE_PUESTO("bosque_06"));
    AddExit("oeste","bosque_08");
    AddExit("este","bosque_10");
    AddExit("sur","bosque_06");
    AddExit("sudeste","bosque_07");
    AddExit("suroeste","bosque_05");
    AddExit("norte","bosque_11");
}