/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera146.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("este",SHERCAN("medio/cantera145"));
    AddExit("sur",SHERCAN("medio/cantera136"));
    AddExit("sudeste",SHERCAN("medio/cantera135"));
    pongo();
}
