/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera126.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("este",SHERCAN("medio/cantera125"));
    AddExit("norte",SHERCAN("medio/cantera136"));
    AddExit("sudeste",SHERCAN("medio/cantera115"));
    pongo();
}
