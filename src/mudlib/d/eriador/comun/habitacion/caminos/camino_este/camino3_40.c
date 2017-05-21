/****
archivo: camino3_40.c
autor: Ulmo 29/11/2014 12:34:46
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_39");
    AddExit("noreste","./camino3_41");

    }
