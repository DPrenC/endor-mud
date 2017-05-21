/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera62.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("suroeste",SHERCAN("alto/cantera53"));
    pongo();
}
