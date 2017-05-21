/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera11.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("noroeste",SHERCAN("alto/cantera22"));
    AddExit("norte",SHERCAN("alto/cantera21"));
    pongo();
}
