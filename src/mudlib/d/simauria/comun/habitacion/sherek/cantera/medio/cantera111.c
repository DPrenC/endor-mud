/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera111.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("noroeste",SHERCAN("medio/cantera122"));
    AddExit("norte",SHERCAN("medio/cantera121"));
    pongo();
}
