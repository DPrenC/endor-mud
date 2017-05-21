/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera42.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("este",SHERCAN("alto/cantera41"));
    AddExit("suroeste",SHERCAN("alto/cantera33"));
    AddExit("nordeste",SHERCAN("alto/cantera51"));
    AddExit("norte",SHERCAN("alto/cantera52"));
    pongo();
}
