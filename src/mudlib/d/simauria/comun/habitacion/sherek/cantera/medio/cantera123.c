/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera123.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("este",SHERCAN("medio/cantera122"));
    AddExit("suroeste",SHERCAN("medio/cantera114"));
    AddExit("sur",SHERCAN("medio/cantera113"));
    AddExit("norte",SHERCAN("medio/cantera133"));
    pongo();
}
