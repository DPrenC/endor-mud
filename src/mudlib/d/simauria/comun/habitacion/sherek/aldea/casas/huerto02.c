/* Archivo        huerto02.c
   Autor:         Yalin y Lug
   Fecha:         05/05/2006
   Descripci�n:   Huerto de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("casas/huerto");


create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al oeste puedes ver la salida hacia la calle "
        "y al sur una ventana de la casa m�s cercana.\n");
    AddExit("oeste", SHERALD("calles/calle02"));
}


