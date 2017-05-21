/****
archivo: camino3_47.c
autor: Ulmo 20/12/2014 16:34:19
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_46");
    AddExit("este","./camino3_48");

    }
