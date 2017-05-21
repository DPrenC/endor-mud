/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera242.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("este",SHERCAN("fondo/cantera241"));
    AddExit("suroeste",SHERCAN("fondo/cantera233"));
    AddExit("nordeste",SHERCAN("fondo/cantera251"));
    AddExit("norte",SHERCAN("fondo/cantera252"));
    pongo();
}
