/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera144.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("este",SHERCAN("medio/cantera143"));
    AddExit("sur",SHERCAN("medio/cantera134"));
    AddExit("norte",SHERCAN("medio/cantera154"));
    AddExit("suroeste",SHERCAN("medio/cantera135"));
    pongo();
}
