/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera245.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("sudeste",SHERCAN("fondo/cantera234"));
    AddExit("oeste",SHERCAN("fondo/cantera246"));
    AddExit("sur",SHERCAN("fondo/cantera235"));
    AddExit("noroeste",SHERCAN("fondo/cantera256"));
    pongo();
}
