/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera53.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("alto/cantera62"));
    AddExit("oeste",SHERCAN("alto/cantera54"));
    AddExit("sur",SHERCAN("alto/cantera43"));
    AddExit("norte",SHERCAN("alto/cantera63"));
    pongo();
}
