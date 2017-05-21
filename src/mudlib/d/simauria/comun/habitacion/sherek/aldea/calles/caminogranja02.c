/* Archivo        caminogranja02.c
Autor:         Yalin y Lug
Fecha:         05/05/2006
Descripci�n:   Camino de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("calles/caminog");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte y al sur puedes ver sendas caba�as, "
        "y hacia el este y el oeste sigue el camino de la granja.\n");
    AddDetail(({"caba�a","caba�as"}),"Puedes ver una pobre caba�a de troncos "
        "mal aserrados y peor unidos entre s�. Lo m�s probable es que ah� "
        "vivan gentes con muy pocos recursos.\n");
    AddExit("este", SHERALD("calles/caminogranja03"));
    AddExit("oeste", SHERALD("calles/caminogranja01"));
    AddExit("norte", SHERALD("casas/cabanya04"));
    AddExit("sur", SHERALD("casas/cabanya03"));
    AddItem(PNJ("sherek/aldea/guardian"), REFRESH_DESTRUCT,1);
}
