/* Archivo        calle02.c
   Autor:         Yalin y Lug
   Fecha:         04/05/2006
   Descripción:   Calle de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("calles/calle");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este puedes ver un huerto, "
        "y al oeste una casa aldeana. Hacia el sur y hacia el norte sigue la "
        "calle por la que vas.\n");
    AddDetail(({"casa", "oeste"}), "Se trata de una pequeña casa de una sola "
        "planta con un tejado de pizarra a dos aguas y pulcramente encalada.\n");
    AddDetail(({"oeste", "huerto"}), "Un simple y pequeño huerto  de algún "
        "aldeano.\n");
    AddExit("este", SHERALD("casas/huerto02"));
    AddExit("oeste", SHERALD("casas/casa00"));
    AddExit("norte", SHERALD("calles/calle01"));
    AddExit("sur", SHERALD("calles/calle03"));
}
