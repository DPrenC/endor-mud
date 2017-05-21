/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera112.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("nordeste",SHERCAN("medio/cantera121"));
    AddExit("oeste",SHERCAN("medio/cantera113"));
    AddExit("norte",SHERCAN("medio/cantera122"));
    pongo();
}
