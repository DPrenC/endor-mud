/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera32.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("este",SHERCAN("alto/cantera31"));
    AddExit("noroeste",SHERCAN("alto/cantera43"));
    AddExit("sur",SHERCAN("alto/cantera22"));
    AddExit("nordeste",SHERCAN("alto/cantera41"));
    pongo();
}
