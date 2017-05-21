/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera233.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("sudeste",SHERCAN("fondo/cantera222"));
    AddExit("oeste",SHERCAN("fondo/cantera234"));
    AddExit("sur",SHERCAN("fondo/cantera223"));
    AddExit("nordeste",SHERCAN("fondo/cantera242"));
    pongo();
}
