/* Archivo        huerto03.c
   Autor:         Yalin y Lug
   Fecha:         05/05/2006
   Descripción:   Huerto de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("casas/huerto");


create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al sur puedes ver la salida hacia la calle y "
        "al oeste una ventana de la casa más cercana.\n");
    AddExit("sur", SHERALD("calles/caminogranja01"));
}


