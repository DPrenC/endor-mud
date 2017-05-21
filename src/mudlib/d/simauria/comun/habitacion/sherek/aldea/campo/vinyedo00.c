/* Archivo:         vi�edo00.c
   Autor:           Yalin y Lug
   Descripci�n:     vi�edos en la aldea de Sloch
   Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el oeste tienes la salida al camino, en las "
        "dem�s direcciones contin�a el vi�edo.\n");
    AddExit("norte", SHERALD("campo/vinyedo13"));
    AddExit("oeste", SHERALD("calles/caminorio05"));
    AddExit("este", SHERALD("campo/vinyedo01"));
    AddExit("sur", SHERALD("campo/vinyedo03"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
