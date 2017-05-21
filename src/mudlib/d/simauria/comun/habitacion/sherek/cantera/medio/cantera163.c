/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera163.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("sudeste",SHERCAN("medio/cantera152"));
    AddExit("suroeste",SHERCAN("medio/cantera154"));
    AddExit("sur",SHERCAN("medio/cantera153"));
    pongo();
}
