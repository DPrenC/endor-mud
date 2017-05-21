/* Archivo:         labranza11.c
Autor:           Yalin y Lug
Descripción:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el sur puedes ver la pared trasera del "
        "granero de la granja, hacia el este está la pared trasera de un "
        "establo. En las demás direcciones continúa la plantación\n");
    AddDetail (({"pared"}),"Se trata de una simple pared construida con "
        "grandes maderos.\n");
    AddDetail(({"granero","establo"}),"sólo ves la pared trasera. No tiene "
        "nada más de interés.\n");
    AddExit("norte", SHERALD("campo/labranza10"));
    AddExit("oeste", SHERALD("campo/labranza15"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
