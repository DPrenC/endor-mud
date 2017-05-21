/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera23.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("este",SHERCAN("alto/cantera22"));
    AddExit("suroeste",SHERCAN("alto/cantera14"));
    AddExit("sur",SHERCAN("alto/cantera13"));
    AddExit("norte",SHERCAN("alto/cantera33"));
    pongo();
}
