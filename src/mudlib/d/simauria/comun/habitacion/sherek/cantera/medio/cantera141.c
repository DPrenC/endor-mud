/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera141.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("oeste",SHERCAN("medio/cantera142"));
    AddExit("norte",SHERCAN("medio/cantera151"));
    AddExit("suroeste",SHERCAN("medio/cantera132"));
    pongo();
}
