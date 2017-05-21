/* Archivo:         vi�edo03.c
Autor:           Yalin y Lug
Descripci�n:     vi�edos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"En todas direcciones contin�an los vi�edos.\n");
    AddExit("norte", SHERALD("campo/vinyedo00"));
    AddExit("sur", SHERALD("campo/vinyedo05"));
    AddExit("oeste", SHERALD("campo/vinyedo02"));
    AddExit("este", SHERALD("campo/vinyedo04"));
    AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,1);
}
