/****
archivo: camino3_49.c
autor: Ulmo 20/12/2014 16:37:07
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_48");
    AddExit("norte","./camino3_50");

    }
