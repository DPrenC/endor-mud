/* Archivo:         labranza10.c
Autor:           Yalin y Lug
Descripción:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este está la pared trasera de un "
        "establo. En las demás direcciones continúa la plantación\n");
    AddDetail (({"pared"}),"Es una pared construida con grandes maderos.\n");
    AddDetail(({"establo"}),"sólo ves la pared trasera. No tiene nada más de "
        "interés.\n");
    AddExit("norte", SHERALD("campo/labranza09"));
    AddExit("sur", SHERALD("campo/labranza11"));
    AddExit("oeste", SHERALD("campo/labranza14"));
}
