/****
archivo: camino3_08.c
autor: Ulmo 16/11/2014 14:44:57
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();

    AddExit("suroeste","./camino3_07");
    AddExit("norte","./camino3_09");

    }
