/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera33.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("sudeste",SHERCAN("alto/cantera22"));
    AddExit("oeste",SHERCAN("alto/cantera34"));
    AddExit("sur",SHERCAN("alto/cantera23"));
    AddExit("nordeste",SHERCAN("alto/cantera42"));
    pongo();
}
