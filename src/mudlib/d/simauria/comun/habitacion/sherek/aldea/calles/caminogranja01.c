/* Archivo caminogranja01.c
Autor:         Yalin y Lug
Fecha:         05/05/2006
Descripción:   Camino de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("calles/caminog");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte tienes un pequeño huerto, al sur hay una "
        "pobre cabaña, al este y al oeste sigue el camino de la granja.\n");
    AddDetail(({"huerto"}),"Es un pequeño huerto de alguna de las "
        "casas de la aldea.\n");
    AddDetail(({"cabañña"}),"Puedes ver una pobre cabaña de troncos mal "
        "aserrados y peor unidos entre sí. Lo más probable es que ahí vivan "
        "gentes con muy pocos recursos.\n");
    AddExit("este", SHERALD("calles/caminogranja02"));
    AddExit("oeste", SHERALD("calles/caminogranja00"));
    AddExit("norte", SHERALD("casas/huerto03"));
    AddExit("sur", SHERALD("casas/cabanya02"));
}
