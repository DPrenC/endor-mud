/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera226.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
    ::create();
    AddExit("este",SHERCAN("fondo/cantera225"));
    AddExit("norte",SHERCAN("fondo/cantera236"));
    AddExit("sudeste",SHERCAN("fondo/cantera215"));
    pongo();
}
