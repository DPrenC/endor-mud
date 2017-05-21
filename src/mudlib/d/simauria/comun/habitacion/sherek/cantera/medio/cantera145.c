/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera145.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("sudeste",SHERCAN("medio/cantera134"));
    AddExit("oeste",SHERCAN("medio/cantera146"));
    AddExit("sur",SHERCAN("medio/cantera135"));
    AddExit("noroeste",SHERCAN("medio/cantera156"));
    pongo();
}
