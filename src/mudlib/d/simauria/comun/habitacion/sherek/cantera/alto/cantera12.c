/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera12.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("nordeste",SHERCAN("alto/cantera21"));
    AddExit("oeste",SHERCAN("alto/cantera13"));
    AddExit("norte",SHERCAN("alto/cantera22"));
    pongo();
}
