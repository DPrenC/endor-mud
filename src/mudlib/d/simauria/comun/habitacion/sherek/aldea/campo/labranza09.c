/* Archivo:         labranza09.c
Autor:           Yalin y Lug
Descripción:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Puedes ver campos de cultivo en todas "
        "direcciones.\n");
    AddExit("norte", SHERALD("campo/labranza08"));
    AddExit("sur", SHERALD("campo/labranza10"));
    AddExit("oeste", SHERALD("campo/labranza13"));
    AddExit("este", SHERALD("campo/labranza05"));
}
