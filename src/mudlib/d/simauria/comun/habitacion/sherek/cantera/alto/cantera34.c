/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera34.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("este",SHERCAN("alto/cantera33"));
    AddExit("noroeste",SHERCAN("alto/cantera45"));
    AddExit("norte",SHERCAN("alto/cantera44"));
    pongo();
}
