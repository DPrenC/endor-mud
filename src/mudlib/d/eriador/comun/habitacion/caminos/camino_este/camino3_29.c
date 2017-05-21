/****
archivo: camino3_29.c
autor: Ulmo 23/11/2014 17:24:01
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_28");
    AddExit("noreste","./camino3_30");

    }
