/****
archivo: camino3_06.c
autor: Ulmo 16/11/2014 14:46:28
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
        AddExit("suroeste","./camino3_05");
    AddExit("este","./camino3_07");

    }
