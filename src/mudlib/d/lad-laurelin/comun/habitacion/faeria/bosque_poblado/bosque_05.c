/***
Fichero: bosque_05.c
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
    SetOficina(HAB_BOSQUE_PUESTO("bosque_03"));
    AddExit("sudeste","bosque_03");
    AddExit("sur","bosque_02");
    AddExit("este","bosque_06");
    AddExit("norte","bosque_08");
    AddExit("nordeste","bosque_09");
}
