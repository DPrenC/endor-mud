/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera154.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
     ::create();
    AddExit("este",SHERCAN("medio/cantera153"));
    AddExit("sur",SHERCAN("medio/cantera144"));
    AddExit("norte",SHERCAN("medio/cantera164"));
    AddExit("nordeste",SHERCAN("medio/cantera163"));
    pongo();
}
