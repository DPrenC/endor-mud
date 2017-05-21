/****
archivo: camino3_50.c
autor: Ulmo 20/12/2014 16:38:39
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_49");
    AddExit("noreste","./camino4_01");

    }
