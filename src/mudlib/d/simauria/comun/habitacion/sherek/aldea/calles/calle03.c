/* Archivo        calle03.c
   Autor:         Yalin y Lug
   Fecha:         04/05/2006
   Descripción:   Calle de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("calles/calle");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al este puedes ver una pequeña casa, al oeste "
        "hay un huerto no muy grande. Al sur y al norte continúa la calle.\n");
    AddDetail(({"casa", "este"}), "Se trata de una pequeña casa de una sola "
        "planta con un tejado de pizarra a dos aguas y pulcramente encalada.\n");
    AddDetail(({"huerto", "oeste"}), "Ves un pequeño huerto donde los "
        "aldeanos plantan sus cosas.\n");
    AddExit("este", SHERALD("casas/casa03"));
    AddExit("oeste", SHERALD("casas/huerto01"));
    AddExit("sur", SHERALD("calles/calle04"));
    AddExit("norte", SHERALD("calles/calle02"));
}
