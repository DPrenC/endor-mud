/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera31.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("oeste",SHERCAN("alto/cantera32"));
    AddExit("norte",SHERCAN("alto/cantera41"));
    AddExit("sur",SHERCAN("alto/cantera21"));
    pongo();
}
