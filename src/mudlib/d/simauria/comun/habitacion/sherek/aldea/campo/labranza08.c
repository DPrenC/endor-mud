/* Archivo:         labranza08.c
Autor:           Yalin y Lug
Descripción:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"En todas direcciones se extiende el sembrado.\n");
    AddExit("norte", SHERALD("campo/labranza07"));
    AddExit("sur", SHERALD("campo/labranza09"));
    AddExit("oeste", SHERALD("campo/labranza12"));
    AddExit("este", SHERALD("campo/labranza06"));
}
