/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera125.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("este",SHERCAN("medio/cantera124"));
    AddExit("oeste",SHERCAN("medio/cantera126"));
    AddExit("suroeste",SHERCAN("medio/cantera116"));
    AddExit("norte",SHERCAN("medio/cantera135"));
    pongo();
}
