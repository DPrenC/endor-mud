/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera41.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("oeste",SHERCAN("alto/cantera42"));
    AddExit("norte",SHERCAN("alto/cantera51"));
    AddExit("suroeste",SHERCAN("alto/cantera32"));
    pongo();
}
