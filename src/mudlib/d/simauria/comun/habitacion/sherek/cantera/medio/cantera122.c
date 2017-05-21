/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera122.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("sudeste",SHERCAN("medio/cantera111"));
    AddExit("oeste",SHERCAN("medio/cantera123"));
    AddExit("sur",SHERCAN("medio/cantera112"));
    AddExit("noroeste",SHERCAN("medio/cantera133"));
    pongo();
}
