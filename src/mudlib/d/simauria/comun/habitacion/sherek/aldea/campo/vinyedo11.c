/* Archivo:         vi�edo11.c
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
    AddExit("norte", SHERALD("campo/vinyedo23"));
    AddExit("este", SHERALD("campo/vinyedo12"));
    AddExit("oeste", SHERALD("campo/vinyedo13"));
    AddExit("sur", SHERALD("campo/vinyedo01"));
    AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,1);
}
