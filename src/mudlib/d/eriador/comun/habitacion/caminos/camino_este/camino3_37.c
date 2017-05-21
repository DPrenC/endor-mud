/****
archivo: camino3_37.c
autor: Ulmo 29/11/2014 12:29:15
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_36");
    AddExit("este","./camino3_38");

    }
