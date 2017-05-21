/****
archivo: camino3_12.c
autor: Ulmo 22/11/2014 12:30:45
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_11");
    AddExit("este","./camino3_13");

    }
