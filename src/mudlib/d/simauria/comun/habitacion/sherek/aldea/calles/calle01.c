/* Archivo        calle01.c
   Autor:         Yalin y Lug
   Fecha:         04/05/2006
   Descripción:   Calle de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("calles/calle");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este puedes ver un descampado, al "
        "oeste hay un pequeño huerto perteneciente a alguna de las casas; "
        "hacia el sur y el norte continúa la calle.\n");
    AddDetail(({"descampado", "este"}), "Es un descampado donde tiempo atrás "
        "hubo una casa que ya no existe.\n");
    AddDetail(({"oeste","huerto"}),"Un simple y pequeño huerto  para el "
        "autoconsumo de alguien.\n");
    AddExit("este", SHERALD("calles/descampado"));
    AddExit("oeste", SHERALD("casas/huerto00"));
    AddExit("norte", SHERALD("calles/calle00"));
    AddExit("sur", SHERALD("calles/calle02"));
}
