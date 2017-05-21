/* Archivo caminogranja01.c
Autor:         Yalin y Lug
Fecha:         05/05/2006
Descripci�n:   Camino de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("calles/caminog");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte tienes un peque�o huerto, al sur hay una "
        "pobre caba�a, al este y al oeste sigue el camino de la granja.\n");
    AddDetail(({"huerto"}),"Es un peque�o huerto de alguna de las "
        "casas de la aldea.\n");
    AddDetail(({"caba��a"}),"Puedes ver una pobre caba�a de troncos mal "
        "aserrados y peor unidos entre s�. Lo m�s probable es que ah� vivan "
        "gentes con muy pocos recursos.\n");
    AddExit("este", SHERALD("calles/caminogranja02"));
    AddExit("oeste", SHERALD("calles/caminogranja00"));
    AddExit("norte", SHERALD("casas/huerto03"));
    AddExit("sur", SHERALD("casas/cabanya02"));
}
