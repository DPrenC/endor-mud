/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera26.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("alto/cantera");

create()
{
    ::create();
    AddExit("este",SHERCAN("alto/cantera25"));
    AddExit("norte",SHERCAN("alto/cantera36"));
    pongo();
}
