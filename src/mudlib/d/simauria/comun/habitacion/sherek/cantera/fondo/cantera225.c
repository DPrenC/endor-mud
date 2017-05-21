/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera225.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("este",SHERCAN("fondo/cantera224"));
    AddExit("oeste",SHERCAN("fondo/cantera226"));
    AddExit("suroeste",SHERCAN("fondo/cantera216"));
    AddExit("norte",SHERCAN("fondo/cantera235"));
    pongo();
}
