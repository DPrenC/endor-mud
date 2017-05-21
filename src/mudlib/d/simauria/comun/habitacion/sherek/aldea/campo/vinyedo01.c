/* Archivo:         vi�edo01.c
Autor:           Yalin y Lug
Descripci�n:     vi�edos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"En todas direcciones se extiende el vi�edo.\n");
    AddExit("norte", SHERALD("campo/vinyedo11"));
    AddExit("este", SHERALD("campo/vinyedo07"));
    AddExit("oeste", SHERALD("campo/vinyedo00"));
    AddExit("sur", SHERALD("campo/vinyedo04"));
}
