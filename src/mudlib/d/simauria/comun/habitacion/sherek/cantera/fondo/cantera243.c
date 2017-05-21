/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera243.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("fondo/cantera252"));
    AddExit("oeste",SHERCAN("fondo/cantera244"));
    AddExit("sudeste",SHERCAN("fondo/cantera232"));
    AddExit("norte",SHERCAN("fondo/cantera253"));
    pongo();
}
