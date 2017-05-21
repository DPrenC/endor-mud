/****
archivo: camino3_09.c
autor: Ulmo 16/11/2014 14:44:04
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("sur","./camino3_08");
    AddExit("noreste","./camino3_10");

    }
