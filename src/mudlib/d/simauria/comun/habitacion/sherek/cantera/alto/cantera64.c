/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera64.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("este",SHERCAN("alto/cantera63"));
    AddExit("sur",SHERCAN("alto/cantera54"));
    pongo();
}
