/* Archivo:         vi�edo04.c
Autor:           Yalin y Lug
Descripci�n:     vi�edos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este el monte te corta el paso "
        "impidi�ndote ir por all�. En las dem�s direcciones contin�a el "
        "vi�edo.\n");
    AddExit("oeste", SHERALD("campo/vinyedo03"));
    AddExit("norte", SHERALD("campo/vinyedo01"));
    AddExit("sur", SHERALD("campo/vinyedo06"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
