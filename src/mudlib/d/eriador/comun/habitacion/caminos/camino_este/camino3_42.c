/****
archivo: camino3_42.c
autor: Ulmo 20/12/2014 16:26:09
tercer tramo del camino del este al este de los pantanos de moscagua.
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("oeste","./camino3_41");
    AddExit("noreste","./camino3_43");

    }
