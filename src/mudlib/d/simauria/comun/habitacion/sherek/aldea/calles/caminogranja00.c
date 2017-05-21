/* Archivo        caminogranja00.c
Autor:         Yalin y Lug
Fecha:         05/05/2006
Descripción:   Camino de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("calles/caminog");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte tienes un muro de una casa, al sur, "
        "un callejón conduce a una pradera, al este vas hacia la granja y al "
        "oeste a la plaza de la aldea.\n");
    AddDetail(({"casa"}), "Ves el muro de una casa.\n");
    AddDetail(({"muro"}), "Se trata de un muro de mampostería encalado: como "
        "los de toda la aldea.\n");
    AddExit("sur", SHERALD("calles/caminop"));
    AddExit("este", SHERALD("calles/caminogranja01"));
    AddExit("oeste", SHERALD("calles/plazoleta"));
}
