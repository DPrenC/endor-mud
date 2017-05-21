/****
archivo: camino3_05.c
autor: Ulmo 16/11/2014 14:46:53
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
        AddExit("suroeste","./camino3_04");
    AddExit("noreste","./camino3_06");

    }
