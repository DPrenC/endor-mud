/****
archivo: camino3_44.c
autor: Ulmo 20/12/2014 16:29:55
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_43");
    AddExit("noreste","./camino3_45");

    }
