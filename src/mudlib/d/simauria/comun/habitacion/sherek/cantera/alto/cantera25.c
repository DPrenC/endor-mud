/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera25.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("este",SHERCAN("alto/cantera24"));
    AddExit("oeste",SHERCAN("alto/cantera26"));
    AddExit("suroeste",SHERCAN("alto/cantera16"));
    AddExit("norte",SHERCAN("alto/cantera35"));
    pongo();
}
