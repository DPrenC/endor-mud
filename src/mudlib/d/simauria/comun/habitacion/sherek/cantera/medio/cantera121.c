/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera121.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("suroeste",SHERCAN("medio/cantera112"));
    AddExit("norte",SHERCAN("medio/cantera131"));
    AddExit("sur",SHERCAN("medio/cantera111"));
    pongo();
}
