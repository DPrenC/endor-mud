/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera43.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("alto/cantera52"));
    AddExit("oeste",SHERCAN("alto/cantera44"));
    AddExit("sudeste",SHERCAN("alto/cantera32"));
    AddExit("norte",SHERCAN("alto/cantera53"));
    pongo();
}
