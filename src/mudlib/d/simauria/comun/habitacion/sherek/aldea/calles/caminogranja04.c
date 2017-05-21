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
        "ser el complejo de la granja.\n");
    AddDetail(({"pastos"}),"puedes ver en ellos unos toros inmensos. "
        "Parecen salvajes.\n");
    AddDetail(({"toro","toros"}),"Parecen temibles!... Mejor no ir a "
        "conocerlos.\n");
    AddDetail(({"tierras","labranza"}),"Son, seguramente, las posesiones de "
        "la granja.\n");
    AddExit("sudeste", SHERALD("calles/caminogranja05"));
    AddExit("noroeste", SHERALD("calles/caminogranja03"));
}
