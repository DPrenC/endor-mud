/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera234.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
    ::create();
    AddExit("este",SHERCAN("fondo/cantera233"));
    AddExit("noroeste",SHERCAN("fondo/cantera245"));
    AddExit("norte",SHERCAN("fondo/cantera244"));
    pongo();
}
