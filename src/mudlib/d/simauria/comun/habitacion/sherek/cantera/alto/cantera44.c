/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera44.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("este",SHERCAN("alto/cantera43"));
    AddExit("sur",SHERCAN("alto/cantera34"));
    AddExit("norte",SHERCAN("alto/cantera54"));
    AddExit("suroeste",SHERCAN("alto/cantera35"));
    pongo();
}
