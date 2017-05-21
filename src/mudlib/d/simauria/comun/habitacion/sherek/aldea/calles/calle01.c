/* Archivo        calle01.c
   Autor:         Yalin y Lug
   Fecha:         04/05/2006
   Descripci�n:   Calle de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("calles/calle");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este puedes ver un descampado, al "
        "oeste hay un peque�o huerto perteneciente a alguna de las casas; "
        "hacia el sur y el norte contin�a la calle.\n");
    AddDetail(({"descampado", "este"}), "Es un descampado donde tiempo atr�s "
        "hubo una casa que ya no existe.\n");
    AddDetail(({"oeste","huerto"}),"Un simple y peque�o huerto  para el "
        "autoconsumo de alguien.\n");
    AddExit("este", SHERALD("calles/descampado"));
    AddExit("oeste", SHERALD("casas/huerto00"));
    AddExit("norte", SHERALD("calles/calle00"));
    AddExit("sur", SHERALD("calles/calle02"));
}
