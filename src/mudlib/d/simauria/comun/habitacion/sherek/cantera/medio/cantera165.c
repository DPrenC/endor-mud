/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera165.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("oeste",SHERCAN("medio/cantera166"));
    AddExit("sur",SHERCAN("medio/cantera155"));
    pongo();
}
