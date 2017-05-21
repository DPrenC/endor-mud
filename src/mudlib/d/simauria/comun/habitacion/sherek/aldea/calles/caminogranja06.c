/* Archivo        caminogranja05.c
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
        "ser dependencias de la granja, y hacia el este está la entrada a "
        "los pastos.\n");
    AddDetail(({"pastos"}), "Ves en ellos unos toros bravos que se pasean.\n");
    AddDetail(({"toro","toros"}),"¡Parecen temibles!, ¡mejor no entrar ahí!\n");
    AddDetail(({"tierras","labranza"}),"Son, seguramente, las posesiones de "
        "la granja.\n");
    AddExit("sur", SHERALD("granja/granja00"));
    AddExit("norte", SHERALD("calles/caminogranja05"));
    AddExit("este", SHERALD("pastos/pastos04"));
    AddItem(PNJ("sherek/aldea/guardian"), REFRESH_DESTRUCT,2);
}
