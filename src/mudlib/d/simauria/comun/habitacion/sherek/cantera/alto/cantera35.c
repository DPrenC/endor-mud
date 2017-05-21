/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera35.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("alto/cantera44"));
    AddExit("noroeste",SHERCAN("alto/cantera46"));
    AddExit("sur",SHERCAN("alto/cantera25"));
    AddExit("norte",SHERCAN("alto/cantera45"));
    pongo();
}
