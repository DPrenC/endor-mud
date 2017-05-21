/****
archivo: camino3_36.c
autor: Ulmo 29/11/2014 12:27:38
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("oeste","./camino3_35");
    AddExit("noreste","./camino3_37");

    }
