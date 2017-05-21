/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera132.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("este",SHERCAN("medio/cantera131"));
    AddExit("noroeste",SHERCAN("medio/cantera143"));
    AddExit("sur",SHERCAN("medio/cantera122"));
    AddExit("nordeste",SHERCAN("medio/cantera141"));
    pongo();
}
