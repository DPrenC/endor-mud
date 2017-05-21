/* Archivo        calle04.c
   Autor:         Yalin y Lug
   Fecha:         04/05/2006
   Descripción:   Calle de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("calles/calle");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al este y al oeste ves sendas casas aldeanas. "
        "Hacia el sur hay una pequeña plaza y hacia el norte continúa la "
        "calle en la que estás.\n");
    AddDetail(({"casa","oeste","este"}),"Se trata de una pequeña casa de una "
        "sola planta con un tejado de pizarra a dos aguas y pulcramente "
        "encalada.\n");
    AddExit("este", SHERALD("casas/casa02"));
    AddExit("oeste", SHERALD("casas/casa01"));
    AddExit("norte", SHERALD("calles/calle03"));
    AddExit("sur", SHERALD("calles/plazoleta"));
}
