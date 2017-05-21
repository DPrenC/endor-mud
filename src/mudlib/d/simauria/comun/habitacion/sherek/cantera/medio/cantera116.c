/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera116.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("nordeste",SHERCAN("medio/cantera125"));
    AddExit("norte",SHERCAN("medio/cantera126"));
    pongo();
}
