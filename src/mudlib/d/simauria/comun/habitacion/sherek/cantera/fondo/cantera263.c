/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera263.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
    ::create();
    AddExit("sudeste",SHERCAN("fondo/cantera252"));
    AddExit("suroeste",SHERCAN("fondo/cantera254"));
    AddExit("sur",SHERCAN("fondo/cantera253"));
    pongo();
}
