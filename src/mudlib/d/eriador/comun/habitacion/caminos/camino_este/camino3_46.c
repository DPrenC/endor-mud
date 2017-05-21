/****
archivo: camino3_46.c
autor: Ulmo 20/12/2014 16:32:50
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_45");
    AddExit("noreste","./camino3_47");

    }
