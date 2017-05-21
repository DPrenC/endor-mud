/* Archivo        caminogranja04.c
Autor:         Yalin y Lug
Fecha:         05/05/2006
Descripción:   Camino de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("calles/caminog");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"En todas direcciones ves pastos y tierras de "
        "labranza. Hacia el sudeste hay un grupo de edificaciones que deben "
        "ser parte de la granja.\n");
    AddDetail(({"pastos","pasto"}),"Ves en ellos algunos inmensos toros. "
        "¡Parecen agresivos!\n");
    AddDetail(({"toro","toros"}),"Parecen temibles... mejor no ir a "
        "conocerlos\n");
    AddDetail(({"tierras","labranza"}),"Son, seguramente, las posesiones de "
        "la granja.\n");
    AddExit("sur", SHERALD("calles/caminogranja06"));
    AddExit("noroeste", SHERALD("calles/caminogranja04"));
    AddExit("este", SHERALD("pastos/pastos05"));
}
