/* Archivo        granja00.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripción:   Calle de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("granja/granja");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte puedes ver el camino que lleva de la "
        "granja a la aldea, al sur sigue la calle, al este está la casa de "
        "los administradores y al oeste puedes ver un establo.\n");
    AddDetail(({"casa","este","casa de los administradores"}),"es una casa "
        "bastante grande construida en piedra y pintada de blanco. Tiene "
        "planta baja y piso superior y está ligeramente alzada sobre el "
        "nivel del suelo, lo que te indica que aquí suele haber inundaciones.\n");
    AddExit("norte", SHERALD("calles/caminogranja06"));
    AddExit("sur", SHERALD("granja/granja01"));
    AddExit("este", SHERALD("casas/casagranja00"));
    AddExit("oeste", SHERALD("granja/establo00"));
    AddItem(PNJ("sherek/aldea/aldeanog"), REFRESH_DESTRUCT,2);
}
