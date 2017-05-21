/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera224.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
    ::create();
    AddExit("oeste",SHERCAN("fondo/cantera225"));
    AddExit("sur",SHERCAN("fondo/cantera214"));
    AddExit("suroeste",SHERCAN("fondo/cantera215"));
    pongo();
}
