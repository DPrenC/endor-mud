/****
archivo: camino3_41.c
autor: Ulmo 20/12/2014 16:24:08
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_40");
    AddExit("este","./camino3_42");

    }
