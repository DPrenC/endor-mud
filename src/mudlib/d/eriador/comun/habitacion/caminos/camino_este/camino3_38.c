/****
archivo: camino3_38.c
autor: Ulmo 29/11/2014 12:30:27
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("oeste","./camino3_37");
    AddExit("noreste","./camino3_39");

    }
