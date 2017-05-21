/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera262.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
    ::create();
    AddExit("suroeste",SHERCAN("fondo/cantera253"));
    pongo();
}
