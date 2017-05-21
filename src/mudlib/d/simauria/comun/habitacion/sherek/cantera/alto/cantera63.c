/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera63.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("sudeste",SHERCAN("alto/cantera52"));
    AddExit("suroeste",SHERCAN("alto/cantera54"));
    AddExit("sur",SHERCAN("alto/cantera53"));
    pongo();
}
