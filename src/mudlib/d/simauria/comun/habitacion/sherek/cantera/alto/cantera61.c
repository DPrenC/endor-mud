/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera61.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripci�n: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("suroeste",SHERCAN("alto/cantera52"));
    AddExit("sur",SHERCAN("alto/cantera51"));
    pongo();
}
