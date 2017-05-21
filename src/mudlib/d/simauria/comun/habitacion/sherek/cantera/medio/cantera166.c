/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera166.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("este",SHERCAN("medio/cantera165"));
    AddExit("sur",SHERCAN("medio/cantera156"));
    pongo();
}
