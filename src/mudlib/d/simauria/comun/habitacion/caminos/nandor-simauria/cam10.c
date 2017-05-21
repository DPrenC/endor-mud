/****************************************************************************
Fichero: cam10.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();
    SetIntLong(QueryIntLong()+ " Una extrechísima senda se introduce en el bosque "
        "hacia el este.\n");
    AddExit("suroeste","./cam11");
    AddExit("norte","./cam09");
    AddExit("nordeste", MARH("nandor/bosque/bosque039"));
    AddExit("este", MARH("nandor/bosque/bosque043"));
    AddExit("sudeste", MARH("nandor/bosque/bosque050"));
    AddExit("sur", MARH("nandor/bosque/bosque049"));
    HideExit("nordeste",1);
    HideExit("sudeste",1);
    HideExit("sur",1);
}

