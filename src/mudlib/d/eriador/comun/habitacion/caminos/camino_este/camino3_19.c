/****
archivo: camino3_19.c
autor: Ulmo 22/11/2014 12:40:55
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_18");
    AddExit("noreste","./camino3_20");

    }
