/***
Fichero: bosque_06.c
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
    SetOficina(HAB_BOSQUE_PUESTO("bosque_03"));
    AddExit("oeste","bosque_05");
    AddExit("noroeste","bosque_08");
    AddExit("este","bosque_07");
    AddExit("nordeste","bosque_10");
    AddExit("sur","bosque_03");
    AddExit("norte","bosque_09");
    AddExit("sudeste","bosque_04");
    AddExit("suroeste","bosque_02");
}