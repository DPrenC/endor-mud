/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera236.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
    ::create();
    AddExit("sudeste",SHERCAN("fondo/cantera225"));
    AddExit("norte",SHERCAN("fondo/cantera246"));
    AddExit("sur",SHERCAN("fondo/cantera226"));
    pongo();
}
