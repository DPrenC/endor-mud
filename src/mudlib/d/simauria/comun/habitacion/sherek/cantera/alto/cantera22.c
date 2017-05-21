/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera22.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("sudeste",SHERCAN("alto/cantera11"));
    AddExit("oeste",SHERCAN("alto/cantera23"));
    AddExit("sur",SHERCAN("alto/cantera12"));
    AddExit("noroeste",SHERCAN("alto/cantera33"));
    pongo();
}
