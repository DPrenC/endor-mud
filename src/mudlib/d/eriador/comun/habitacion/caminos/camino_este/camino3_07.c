/****
archivo: camino3_07.c
autor: Ulmo 16/11/2014 14:45:40
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua

****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
        AddExit("oeste","./camino3_06");
    AddExit("noreste","./camino3_08");

    }
