/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera52.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("alto/cantera61"));
    AddExit("noroeste",SHERCAN("alto/cantera63"));
    AddExit("suroeste",SHERCAN("alto/cantera43"));
    AddExit("sur",SHERCAN("alto/cantera42"));
    pongo();
}
