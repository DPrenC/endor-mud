/****
archivo: camino3_10.c
autor: Ulmo 22/11/2014 12:27:01
tercer tramo del camino del este rodeando en su parte este a los pantanos de moscagua
****/

#include "./path.h"

inherit CAMINO_ESTE_ERIADOR("camino3_base");

create(){
    ::create();
    AddExit("suroeste","./camino3_09");
    AddExit("norte","./camino3_11");

    }
