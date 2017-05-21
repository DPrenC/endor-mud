/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera152.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("medio/cantera161"));
    AddExit("noroeste",SHERCAN("medio/cantera163"));
    AddExit("suroeste",SHERCAN("medio/cantera143"));
    AddExit("sur",SHERCAN("medio/cantera142"));
    pongo();
}
