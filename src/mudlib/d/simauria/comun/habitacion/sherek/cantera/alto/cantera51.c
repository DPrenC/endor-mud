/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera51.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("norte",SHERCAN("alto/cantera61"));
     AddExit("sur",SHERCAN("alto/cantera41"));
    pongo();
}
