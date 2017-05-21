/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera142.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("este",SHERCAN("medio/cantera141"));
    AddExit("suroeste",SHERCAN("medio/cantera133"));
    AddExit("nordeste",SHERCAN("medio/cantera151"));
    AddExit("norte",SHERCAN("medio/cantera152"));
    pongo();
}
