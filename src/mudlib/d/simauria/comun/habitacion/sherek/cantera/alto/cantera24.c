/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera24.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("oeste",SHERCAN("alto/cantera25"));
    AddExit("sur",SHERCAN("alto/cantera14"));
    AddExit("suroeste",SHERCAN("alto/cantera15"));
    pongo();
}
