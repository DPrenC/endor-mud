/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera161.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripci�n: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("suroeste",SHERCAN("medio/cantera152"));
    AddExit("sur",SHERCAN("medio/cantera151"));
    pongo();
}
