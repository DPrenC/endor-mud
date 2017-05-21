/* Archivo        calle04.c
   Autor:         Yalin y Lug
   Fecha:         04/05/2006
   Descripci�n:   Calle de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("calles/calle");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al este y al oeste ves sendas casas aldeanas. "
        "Hacia el sur hay una peque�a plaza y hacia el norte contin�a la "
        "calle en la que est�s.\n");
    AddDetail(({"casa","oeste","este"}),"Se trata de una peque�a casa de una "
        "sola planta con un tejado de pizarra a dos aguas y pulcramente "
        "encalada.\n");
    AddExit("este", SHERALD("casas/casa02"));
    AddExit("oeste", SHERALD("casas/casa01"));
    AddExit("norte", SHERALD("calles/calle03"));
    AddExit("sur", SHERALD("calles/plazoleta"));
}
