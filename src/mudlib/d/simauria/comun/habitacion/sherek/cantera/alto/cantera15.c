/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera15.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("noroeste",SHERCAN("alto/cantera16"));
    AddExit("nordeste",SHERCAN("alto/cantera24"));
    pongo();
}
