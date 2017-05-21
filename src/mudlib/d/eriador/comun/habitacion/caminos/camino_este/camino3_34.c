/****
archivo: camino3_34.c
autor: Ulmo 29/11/2014 12:24:56
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_33");
    AddExit("este","./camino3_35");

    }
