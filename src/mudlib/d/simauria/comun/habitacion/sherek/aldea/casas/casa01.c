/* Archivo        casa01.c
   Autor:         Yalin y Lug
   Fecha:         04/05/2006
   Descripci�n:   casa de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("casas/casa");

create ()
{
    ::create();
    AddExit("este", SHERALD("calles/calle04"));
}
