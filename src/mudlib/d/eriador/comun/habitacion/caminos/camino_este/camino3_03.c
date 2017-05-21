/****
archivo: camino3_03.c
autor: Ulmo 16/11/2014 14:47:44
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
        AddExit("suroeste","./camino3_02");
    AddExit("norte","./camino3_04");

    }
