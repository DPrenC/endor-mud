/****
archivo: camino3_18.c
autor: Ulmo 22/11/2014 12:39:22
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_17");
    AddExit("norte","./camino3_19");

    }
