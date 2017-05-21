/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera136.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("sudeste",SHERCAN("medio/cantera125"));
    AddExit("norte",SHERCAN("medio/cantera146"));
    AddExit("sur",SHERCAN("medio/cantera126"));
    pongo();
}
