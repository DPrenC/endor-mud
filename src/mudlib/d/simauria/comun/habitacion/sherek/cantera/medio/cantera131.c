/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera131.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("oeste",SHERCAN("medio/cantera132"));
    AddExit("norte",SHERCAN("medio/cantera141"));
    AddExit("sur",SHERCAN("medio/cantera121"));
    pongo();
}
