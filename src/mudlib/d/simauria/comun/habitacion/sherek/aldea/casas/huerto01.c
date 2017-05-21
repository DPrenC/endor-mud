/* Archivo        huerto01.c
   Autor:         Yalin y Lug
   Fecha:         05/05/2006
   Descripción:   Huerto de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("casas/huerto");


create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al este puedes ver la salida hacia la calle y "
        "al sur una ventana de la casa más cercana.\n");
    AddExit("este", SHERALD("calles/calle03"));
}


