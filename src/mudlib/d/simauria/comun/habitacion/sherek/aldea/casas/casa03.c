/* Archivo        casa03.c
   Autor:         Yalin y Lug
   Fecha:         04/05/2006
   Descripci�n:   casa de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("casas/casa");

create ()
{
    ::create();
    AddExit("oeste", SHERALD("calles/calle03"));
}
