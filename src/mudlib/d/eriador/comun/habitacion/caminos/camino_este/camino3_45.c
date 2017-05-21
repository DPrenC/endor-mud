/****
archivo: camino3_45.c
autor: Ulmo 20/12/2014 16:31:24
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_44");
    AddExit("noreste","./camino3_46");

    }
