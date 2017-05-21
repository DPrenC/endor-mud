/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera46.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("este",SHERCAN("alto/cantera45"));
    AddExit("sur",SHERCAN("alto/cantera36"));
    AddExit("sudeste",SHERCAN("alto/cantera35"));
    pongo();
}
