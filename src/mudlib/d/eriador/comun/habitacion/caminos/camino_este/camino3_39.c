/****
archivo: camino3_39.c
autor: Ulmo 29/11/2014 12:32:06
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_38");
    AddExit("norte","./camino3_40");

    }
