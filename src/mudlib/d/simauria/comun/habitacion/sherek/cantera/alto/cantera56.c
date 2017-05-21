/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera56.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("norte",SHERCAN("alto/cantera66"));
    AddExit("sudeste",SHERCAN("alto/cantera45"));
    pongo();
}
