/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera133.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("sudeste",SHERCAN("medio/cantera122"));
    AddExit("oeste",SHERCAN("medio/cantera134"));
    AddExit("sur",SHERCAN("medio/cantera123"));
    AddExit("nordeste",SHERCAN("medio/cantera142"));
    pongo();
}
