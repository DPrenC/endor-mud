/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera54.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("este",SHERCAN("alto/cantera53"));
    AddExit("sur",SHERCAN("alto/cantera44"));
    AddExit("norte",SHERCAN("alto/cantera64"));
    AddExit("nordeste",SHERCAN("alto/cantera63"));
    pongo();
}
