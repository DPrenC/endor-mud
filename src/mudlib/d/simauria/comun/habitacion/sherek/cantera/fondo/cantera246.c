/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera246.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
    ::create();
    AddExit("este",SHERCAN("fondo/cantera245"));
    AddExit("sur",SHERCAN("fondo/cantera236"));
    AddExit("sudeste",SHERCAN("fondo/cantera235"));
    pongo();
}
