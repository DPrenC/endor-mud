/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera134.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("este",SHERCAN("medio/cantera133"));
    AddExit("noroeste",SHERCAN("medio/cantera145"));
    AddExit("norte",SHERCAN("medio/cantera144"));
    pongo();
}
