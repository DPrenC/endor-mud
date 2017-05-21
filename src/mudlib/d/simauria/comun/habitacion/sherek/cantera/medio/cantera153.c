/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera153.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("medio/cantera162"));
    AddExit("oeste",SHERCAN("medio/cantera154"));
    AddExit("sur",SHERCAN("medio/cantera143"));
    AddExit("norte",SHERCAN("medio/cantera163"));
    pongo();
}
