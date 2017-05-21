/****
archivo: camino3_30.c
autor: Ulmo 23/11/2014 17:25:21
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_29");
    AddExit("norte","./camino3_31");

    }
