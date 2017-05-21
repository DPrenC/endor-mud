/****
archivo: camino3_31.c
autor: Ulmo 29/11/2014 12:15:34
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_30");
    AddExit("norte","./camino3_32");

    }
