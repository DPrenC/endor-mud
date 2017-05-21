/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera222.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("sudeste",SHERCAN("fondo/cantera211"));
    AddExit("oeste",SHERCAN("fondo/cantera223"));
    AddExit("sur",SHERCAN("fondo/cantera212"));
    AddExit("noroeste",SHERCAN("fondo/cantera233"));
    pongo();
}
