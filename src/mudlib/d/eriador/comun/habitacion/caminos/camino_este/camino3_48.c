/****
archivo: camino3_48.c
autor: Ulmo 20/12/2014 16:35:50
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("oeste","./camino3_47");
    AddExit("noreste","./camino3_49");

    }
