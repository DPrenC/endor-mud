/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera135.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("medio/cantera144"));
    AddExit("noroeste",SHERCAN("medio/cantera146"));
    AddExit("sur",SHERCAN("medio/cantera125"));
    AddExit("norte",SHERCAN("medio/cantera145"));
    pongo();
}
