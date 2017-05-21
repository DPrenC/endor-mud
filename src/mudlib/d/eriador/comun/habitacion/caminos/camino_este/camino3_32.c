/****
archivo: camino3_32.c
autor: Ulmo 29/11/2014 12:21:09
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_31");
    AddExit("noreste","./camino3_33");

    }
