/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera215.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripci�n: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
    ::create();
    AddExit("noroeste",SHERCAN("fondo/cantera226"));
    AddExit("nordeste",SHERCAN("fondo/cantera224"));
    pongo();
}
