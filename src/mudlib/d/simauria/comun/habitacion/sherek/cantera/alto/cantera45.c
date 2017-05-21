/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera45.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("sudeste",SHERCAN("alto/cantera34"));
    AddExit("oeste",SHERCAN("alto/cantera46"));
    AddExit("sur",SHERCAN("alto/cantera35"));
    AddExit("noroeste",SHERCAN("alto/cantera56"));
    pongo();
}
