/****
archivo: camino3_35.c
autor: Ulmo 29/11/2014 12:26:16
tercer tramo del camino del este al este de los pantanos de moscagua.

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("oeste","./camino3_34");
    AddExit("este","./camino3_36");

    }
