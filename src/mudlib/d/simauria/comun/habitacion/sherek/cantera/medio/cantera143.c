/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera143.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("medio/cantera152"));
    AddExit("oeste",SHERCAN("medio/cantera144"));
    AddExit("sudeste",SHERCAN("medio/cantera132"));
    AddExit("norte",SHERCAN("medio/cantera153"));
    pongo();
}
