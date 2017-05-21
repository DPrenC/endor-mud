/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera21.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("suroeste",SHERCAN("alto/cantera12"));
    AddExit("norte",SHERCAN("alto/cantera31"));
    AddExit("sur",SHERCAN("alto/cantera11"));
    pongo();
}
