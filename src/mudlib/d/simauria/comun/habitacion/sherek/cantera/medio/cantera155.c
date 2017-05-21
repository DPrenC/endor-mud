/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera155.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("norte",SHERCAN("medio/cantera165"));
    pongo();
}
